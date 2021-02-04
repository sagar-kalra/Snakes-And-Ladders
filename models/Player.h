#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h>
using namespace std;

class Player
{
    int id, currPos;
    string name;

public:
    Player(int, string);
    string getPlayerName();
    int getCurrPos();
    void changeCurrPos(int);
};

#endif