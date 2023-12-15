/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** NcursesController.hpp
*/
#include "../include/NcursesController.hpp"
#include <memory>

std::unique_ptr<IGfxController> factory(void)
{
    return std::make_unique<NcursesController>();
}
