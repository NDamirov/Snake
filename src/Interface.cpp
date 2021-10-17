#include "Interface.h"

#include <ncurses.h>

Interface::Interface(size_t field_w, size_t field_h) {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    curs_set(0);
    for (size_t i = 0; i < field_h; ++i) {
        for (size_t j = 0; j < field_w; ++j) {
            printw(".");
        }
        printw("\n");
    }
}

bool Interface::WasPressed() {
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return true;
    } else {
        return false;
    }
}

int Interface::WhatPressed() {
    int pressed =  getch();
    refresh();
    return pressed;
}

void Interface::Print(std::string str) {
    printw(str.c_str());
    refresh();
}

Interface::~Interface() {
    endwin();
}

void Interface::PrintPos(size_t h, size_t w, const char *str) {
    mvprintw(h, w, str);
    refresh();
}

void Interface::Clear() {
    clear();
}
