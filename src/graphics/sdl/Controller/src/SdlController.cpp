/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** .
*/

#include "../include/SdlController.hpp"
#include <memory>

std::unique_ptr<IGfxController> factory(void) { return std::make_unique<SDLController>(); }
