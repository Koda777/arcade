/*
** EPITECH PROJECT, 2023
** ncurses
** File description:
** NcursesNcursesDisplay.cpp
*/
#include "../include/NcursesDisplay.hpp"
#include <ncurses.h>

NcursesDisplay::NcursesDisplay(void) : win_(nullptr, &delwin)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    std::cout << "Ncurses Display" << std::endl;
    getch();
}

NcursesDisplay::~NcursesDisplay(void)
{
    win_.reset();
    endwin();
}

void NcursesDisplay::init_gfx(std::vector<std::string> &gameGrid)
{
    win_.reset(newwin(
        gameGrid.size() + 2, COLS - 4, (LINES - gameGrid.size() - 2) / 2, 2));
    for (size_t i = 0; i < gameGrid.size(); i++)
        mvwprintw(win_.get(), i + 1, 2, gameGrid[i].c_str());
    wrefresh(win_.get());
}

void NcursesDisplay::display_score(int score, int pos_x, int pos_y)
{
    mvwprintw(win_.get(), pos_y, pos_x, "Score: %d", score);
    wrefresh(win_.get());
    return;
}

int NcursesDisplay::update(std::vector<std::string> &gameGrid)
{
    wclear(win_.get());
    for (size_t i = 0; i < gameGrid.size(); i++)
        mvwprintw(win_.get(), i + 1, 2, gameGrid[i].c_str());
    wrefresh(win_.get());
    return 0;
}

void NcursesDisplay::micro_sleep(int sleep)
{
    (void) sleep;
    return;
}

void NcursesDisplay::display_end(int seconds, int score, int maxx, int maxy)
{
    (void) seconds;
    (void) score;
    (void) maxx;
    (void) maxy;
}

void NcursesDisplay::close_window(void)
{
    //endwin();
    return;
}

void NcursesDisplay::display_chara(int x, int y, char chara)
{
    (void) x;
    (void) y;
    (void) chara;
    return;
}

void NcursesDisplay::clear_window()
{
    wclear(win_.get());
    return;
}
