#include <iostream>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe() {
    this -> playersTurn = "O";
    this -> board = Board();
    this -> numberOfTurns = 0;
}

void TicTacToe::play() {
    while (!(this -> isGameOver())) {
        this -> playersTurn = (playersTurn == "X") ? "O" : "X"; // determine next players move
        this -> board.ToString(); // Display board.
        int position = this -> getPlayersInput();
        this -> board.updateBoard(position, this -> playersTurn);
        this -> numberOfTurns++;
    }

    this -> board.ToString(); // game over, display final state of board
    cout << endl;
}

int TicTacToe::getPlayersInput() {
    const string enterMessage = "Enter the position of the square to place your piece";
    const string invalidPositionMessage = "Invalid position, try again...";

    cout << "Player " << this -> playersTurn << "'s Turn..." << endl;
    cout << enterMessage << endl;
    
    int positionToPlace;
    cin >> positionToPlace;
    while (!isMoveValid(positionToPlace)) {
        cout << invalidPositionMessage << endl;
        cin >> positionToPlace;
    }

    return positionToPlace - 1; // user will input 1 - 9 so minus by 1 to get board position
}

bool TicTacToe::isGameOver() {
    if (this -> numberOfTurns < 5) { return false; }
    string winningCondition = (this -> playersTurn == "X") ? "XXX" : "OOO"; // determine next players move
    // check every row
    for (int i = 0; i <= 6; i += 3) {
        if (this -> board.getValueAtPosition(i) +
            this -> board.getValueAtPosition(i+1) +
            this -> board.getValueAtPosition(i+2) == winningCondition
        ) {
            cout << "Game over, " << this -> playersTurn << " wins!" << endl;
            return true;
        }
    }

    // check every col
    for (int i = 0; i <= 2; i++) {
        if (this -> board.getValueAtPosition(i) +
            this -> board.getValueAtPosition(i+3) +
            this -> board.getValueAtPosition(i+6) == winningCondition
        ) {
            cout << "Game over, " << this -> playersTurn << " wins!" << endl;
            return true;
        }
    }

    // check diagonals
    if (this -> board.getValueAtPosition(0) +
        this -> board.getValueAtPosition(4) +
        this -> board.getValueAtPosition(8) == winningCondition
        ||
        (this -> board.getValueAtPosition(2) +
        this -> board.getValueAtPosition(4) +
        this -> board.getValueAtPosition(6) == winningCondition)
        ) 
    {
        cout << "Game over, " << this -> playersTurn << " wins!" << endl;
        return true;
    }
    
    if (this -> numberOfTurns == 9) {
        cout << "Tie game!" << endl;
        return true;
    }
    return false;
}

Board TicTacToe::getBoard() { return this -> board; }

bool TicTacToe::isMoveValid(int position) {
    if (0 < position || position < 10) {
        const string boardValueAtPosition = this -> board.getValueAtPosition(position - 1);
        if (boardValueAtPosition != "X" && boardValueAtPosition != "O") {
            return true;
        }
    }

    return false;
}