#include <dlfcn.h>
#include "../../exceptions/include/CoreExceptions.hpp"
#include "../../include/core.hpp"

Arcade::Library::Library(const std::string &filename)
{
    std::string path = filename;
    if (path.starts_with("./") == false) {
        std::cout << "path starts with ./ : " << path << std::endl;
        path = "./" + path;
    }
    handle_ = dlopen(path.c_str(), RTLD_LAZY);
    this->filename_ = path;
    std::cout << "init : " << path << std::endl;
    if (!handle_) {
        throw WrongFormatException(dlerror());
    }
}

Arcade::Library::~Library()
{
    this->close();
}

bool Arcade::Library::close()
{
    if (handle_) {
        dlclose(handle_);
        return true;
    }
    return false;
}

void *Arcade::Library::load_symbol(const std::string &symbol)
{
    if (!handle_) {
        throw NoLibException("No library loaded");
    }
    try {
        return dlsym(handle_, symbol.c_str());
    } catch (const std::exception &ex) {
        throw WrongFormatException(dlerror());
    }
}

bool Arcade::Library::changeLib(const std::string &filename)
{
    if (handle_) {
        dlclose(handle_);
    }
    handle_ = dlopen(filename.c_str(), RTLD_LAZY);
    this->filename_ = filename;
    std::cout << "init  from changelib: " << filename << std::endl;
    if (!handle_) {
        throw WrongFormatException(dlerror());
    }
    return true;
}

std::string Arcade::Library::getFilename() const
{
    return filename_;
}
