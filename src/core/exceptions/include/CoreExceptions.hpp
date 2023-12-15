#pragma once
#include <exception>
#include <string>

namespace Arcade
{
    class CoreException : public std::exception {
      private:
        std::string _errorMessage;

      public:
        CoreException(const std::string &msg) noexcept : _errorMessage(msg)
        {
        }
        const char *what() const noexcept override
        {
            return this->_errorMessage.c_str();
        }
    };

    class NoLibException : public std::exception {
      private:
        std::string _errorMessage;

      public:
        NoLibException(const std::string &msg) noexcept : _errorMessage(msg)
        {
        }
        const char *what() const noexcept override
        {
            return this->_errorMessage.c_str();
        }
    };

    class WrongFormatException : public std::exception {
      private:
        std::string _errorMessage;

      public:
        WrongFormatException(const std::string &msg) noexcept
            : _errorMessage(msg)
        {
        }
        const char *what() const noexcept override
        {
            return this->_errorMessage.c_str();
        }
    };
}; // namespace Arcade
