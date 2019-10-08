#include <iostream>
#include "Board.h"

Board::Board() {
    for (int i = 0; i < 9; i ++ ) {
        this -> board[i] = to_string(i+1);
    }
}

string Board::getValueAtPosition(int position) {
    return this -> board[position];
}

void Board::updateBoard(int position, string value) {
    this -> board[position] = value;
}

void Board::ToString() {
    for(int i = 0; i < 9; i ++ ) {
        cout << ' ' << this -> board[i];
        if (i != 2 && i != 5 && i != 8) {
            cout << ' ' << '|';
        } else if (i == 2 || i == 5 || i == 8) { 
            const string rowDivider = "---+---+---";
            cout << endl << rowDivider << endl;
        }
    }
}