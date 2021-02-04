#include <bits/stdc++.h>
#include "models/Player.h"
#include "models/Snake.h"
#include "models/Ladder.h"

#include "services/SnakeAndLadderService.h"

using namespace std;

int main()
{
    int numOfSnakes, numOfLadders, numOfPlayers;
    vector<Snake> snakes;
    vector<Ladder> ladders;
    queue<Player> players;

    cin >> numOfSnakes;
    for (int i = 0; i < numOfSnakes; ++i)
    {
        int startOfSnake, endOfSnake;
        cin >> startOfSnake >> endOfSnake;
        Snake snake = Snake(startOfSnake, endOfSnake);
        snakes.push_back(snake);
    }

    cin >> numOfLadders;
    for (int i = 0; i < numOfLadders; ++i)
    {
        int startOfLadder, endOfLadder;
        cin >> startOfLadder >> endOfLadder;
        Ladder ladder = Ladder(startOfLadder, endOfLadder);
        ladders.push_back(ladder);
    }

    cin >> numOfPlayers;
    for (int i = 0; i < numOfPlayers; ++i)
    {
        string nameOfPlayer;
        cin >> nameOfPlayer;
        Player player = Player(i, nameOfPlayer);
        players.push(player);
    }

    SnakeAndLadderService snakeAndLadderService = SnakeAndLadderService();
    snakeAndLadderService.setSnakes(numOfSnakes, snakes);
    snakeAndLadderService.setLadders(numOfLadders, ladders);
    snakeAndLadderService.setPlayers(numOfPlayers, players);

    snakeAndLadderService.startGame();
}
