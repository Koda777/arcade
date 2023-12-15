/*
** EPITECH PROJECT, 2023
** graphics
** File description:
** .
*/

#include "../include/SfmlController.hpp"

std::unique_ptr<IGfxController> factory(void)
{
    return std::make_unique<SFMLController>();
}
