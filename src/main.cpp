/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/
#include <iostream>
#include <signal.h>
#include "core/include/core.hpp"

void signal_handler(int signum)
{
    (void)signum;
    exit(84);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./arcade [lib.so]" << std::endl;
        return 84;
    }
    //signal(SIGSEGV, signal_handler);
    // signal(SIGABRT, signal_handler);
    try {
        Arcade::Core core(av[1]);
        core.reloadGraphic();
        core.reloadGame();
        core.setUsername("KarimEnScooter92");
        std::cout << "Logged in as " << core.getUsername() << std::endl;
        core.runGraphic();
        core.exitAll();
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
