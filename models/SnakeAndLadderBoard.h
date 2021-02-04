#ifndef SNAKEANDLADDERBOARD_H
#define SNAKEANDLADDERBOARD_H

#include <bits/stdc++.h>
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"
using namespace std;

class SnakeAndLadderBoard
{
    int boardSize, numOfSnakes, numOfLadders;
    vector<Snake> snakes;
    vector<Ladder> ladders;

public:
    SnakeAndLadderBoard();
    SnakeAndLadderBoard(int);
    int getBoardSize();
    void setSnakes(int, vector<Snake>);
    void setLadders(int, vector<Ladder>);
    int checkAndGetCorrespondingSnakeEnd(int);
    int checkAndGetCorrespondingLadderEnd(int);
};

#endif