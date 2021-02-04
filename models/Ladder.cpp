#include "Ladder.h"

Ladder::Ladder(int _start, int _end)
{
    start = _start;
    end = _end;
}

int Ladder::getStart()
{
    return start;
}

int Ladder::getEnd()
{
    return end;
}