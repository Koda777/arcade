/*
** EPITECH PROJECT, 2023
** core parser
** File description:
** arcade
*/

#include "../include/Parser.hpp"
#include <exception>
#include <stdexcept>

// Create a Parser object
Parser::Parser(std::string defaultPath)
{
    std::cout << "Parser created" << std::endl;
    // Set the default path
    _defaultPath = defaultPath;
    if (_defaultPath.starts_with("./") == false)
        _defaultPath = "./" + _defaultPath;
    // Reload the parser
    reload();
    std::cout << "Parser reloaded" << std::endl;
    std::cout << "Games: " << std::endl;
    // Display the games
    for (const auto &game : _games) {
        std::cout << game << std::endl;
    }
    std::cout << "Graphics: " << std::endl;
    // Display the graphics
    for (const auto &graphic : _graphics) {
        std::cout << graphic << std::endl;
    }
}

bool Parser::reload()
{
    // Clear the lists of games and graphics libraries
    _games.clear();
    _graphics.clear();
    _libs.clear();

    // Get the list of .so files in the default path
    for (const auto &entry :
        std::filesystem::directory_iterator(_defaultPath)) {
        if (entry.path().extension() == ".so") {
            _libs.push_back(entry.path());
        }
    }
    if (_libs.empty()) {
        throw std::invalid_argument("No .so files found in the lib folder");
    }

    // For each .so file, check if it is a game or a graphic library
    for (const auto &entry : _libs) {
        for (const auto &game : GAMES_LIBRARIES) {
            if (entry == game) {
                _games.push_back(entry);
            }
        }
        for (const auto &graphic : GRAPHICS_LIBRARIES) {
            if (entry == graphic) {
                _graphics.push_back(entry);
            }
        }
    }
    return true;
}

std::vector<std::string> Parser::getGames()
{
    return _games;
}

std::vector<std::string> Parser::getGraphics()
{
    return _graphics;
}
