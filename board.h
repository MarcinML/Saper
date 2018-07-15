#pragma once
#include <iostream>

class Board
{
public:
    Board();
    int win;
    char board[10][10];
    char userBoard[10][10];

    int checkGame();
    void checkInternal(int, int);
    void show();
    void userInput();
    void getMines();
    void checkEmptyField(int x, int y);
    void moveTouserBoard(int x, int y);
};
