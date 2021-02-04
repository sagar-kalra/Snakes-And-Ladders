#include "Player.h"

Player::Player(int _id, string _name)
{
    id = _id;
    name = _name;
    currPos = 0;
}

string Player::getPlayerName() {
    return name;
}

int Player::getCurrPos()
{
    return currPos;
}

void Player::changeCurrPos(int _newPos)
{
    currPos = _newPos;
}