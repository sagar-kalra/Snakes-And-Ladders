#include "Snake.h"

Snake::Snake(int _start, int _end)
{
    start = _start;
    end = _end;
}

int Snake::getStart()
{
    return start;
}

int Snake::getEnd()
{
    return end;
}