using namespace std;
#include <iostream>
#include "Board.h"

class TicTacToe {
    private:
    Board board;
    Board getBoard();
    string playersTurn;
    int numberOfTurns;
    int getPlayersInput();
    bool isGameOver();
    bool isMoveValid(int);
    
    public:
    TicTacToe();
    void play();
};
