#include "../models/SnakeAndLadderBoard.h"
#include "../models/Player.h"

class SnakeAndLadderService
{
    SnakeAndLadderBoard snakeAndLadderBoard;
    int numOfPlayers;
    queue<Player> players;

public:
    SnakeAndLadderService();
    void setPlayers(int, queue<Player>);
    void setSnakes(int, vector<Snake>);
    void setLadders(int, vector<Ladder>);
    int getFinalPositionConsideringSnakesAndLadders(int);
    Player getCurrentPlayer();
    void startGame();
    bool isGameCompleted();
};