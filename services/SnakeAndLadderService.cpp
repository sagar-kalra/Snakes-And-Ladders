#ifndef SNAKEANDLADDERBOARDSERVICE_H
#define SNAKEANDLADDERBOARDSERVICE_H

#include "SnakeAndLadderService.h"
#include "../models/SnakeAndLadderBoard.h"
#include "Dice.h"

int BOARD_SIZE = 100;

SnakeAndLadderService::SnakeAndLadderService()
{
    snakeAndLadderBoard = SnakeAndLadderBoard(BOARD_SIZE);
}

void SnakeAndLadderService::setPlayers(int _numOfPlayers, queue<Player> _players)
{
    numOfPlayers = _numOfPlayers;
    players = _players;
}

bool SnakeAndLadderService::isGameCompleted()
{
    return players.size() < numOfPlayers;
}

void SnakeAndLadderService::setSnakes(int _numOfSnakes, vector<Snake> _snakes)
{
    snakeAndLadderBoard.setSnakes(_numOfSnakes, _snakes);
}

void SnakeAndLadderService::setLadders(int _numOfLadders, vector<Ladder> _ladders)
{
    snakeAndLadderBoard.setLadders(_numOfLadders, _ladders);
}

Player SnakeAndLadderService::getCurrentPlayer()
{
    Player player = players.front();
    players.pop();
    return player;
}

int SnakeAndLadderService::getFinalPositionConsideringSnakesAndLadders(int currPos)
{
    int endOfSnake = snakeAndLadderBoard.checkAndGetCorrespondingSnakeEnd(currPos);
    if (endOfSnake != -1)
    {
        // cout << "Bitten by snake " << endOfSnake;
        return endOfSnake;
    }

    int endOfLadder = snakeAndLadderBoard.checkAndGetCorrespondingLadderEnd(currPos);
    if (endOfLadder != -1)
        return endOfLadder;

    return currPos;
}

void SnakeAndLadderService::startGame()
{
    while (!isGameCompleted())
    {
        Player player = getCurrentPlayer();
        int currPositionOfPlayer = player.getCurrPos();
        string playerName = player.getPlayerName();
        int numOnDice = rollDice();
        int newPositionOfPlayer = currPositionOfPlayer + numOnDice;
        int boardSize = snakeAndLadderBoard.getBoardSize();
        if (newPositionOfPlayer > boardSize)
        {
            cout << playerName << " chance's is invalid!";
            players.push(player);
        }
        else if (newPositionOfPlayer == boardSize)
        {
            cout << playerName << " has won the game!";
        }
        else
        {
            cout << playerName << " rolled a " << numOnDice << " and moved from " << currPositionOfPlayer;
            int updatedPos = getFinalPositionConsideringSnakesAndLadders(newPositionOfPlayer);
            cout << " to " << updatedPos << "!";
            player.changeCurrPos(updatedPos);
            players.push(player);
        }
        cout << endl;
    }
}

#endif