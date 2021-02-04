#include "SnakeAndLadderBoard.h"

SnakeAndLadderBoard::SnakeAndLadderBoard() {}

SnakeAndLadderBoard::SnakeAndLadderBoard(int _boardSize)
{
    boardSize = _boardSize;
}

int SnakeAndLadderBoard::getBoardSize()
{
    return boardSize;
}

void SnakeAndLadderBoard::setSnakes(int _numOfSnakes, vector<Snake> _snakes)
{
    numOfSnakes = _numOfSnakes;
    snakes = _snakes;
}

void SnakeAndLadderBoard::setLadders(int _numOfLadders, vector<Ladder> _ladders)
{
    numOfLadders = _numOfLadders;
    ladders = _ladders;
}

int SnakeAndLadderBoard::checkAndGetCorrespondingSnakeEnd(int _start)
{
    for (int i = 0; i < numOfSnakes; ++i)
    {
        if (snakes[i].getStart() == _start)
            return snakes[i].getEnd();
    }
    return -1;
}

int SnakeAndLadderBoard::checkAndGetCorrespondingLadderEnd(int _start)
{
    for (int i = 0; i < numOfLadders; ++i)
    {
        if (ladders[i].getStart() == _start)
            return ladders[i].getEnd();
    }
    return -1;
}