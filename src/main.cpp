#include <iostream>
#include <vector>
#include <string>
#include "TicTacToe.h"

using namespace std;

int main() {
    string replay = "n";
    do {
        TicTacToe game;
        game.play();
        cout << "Play again? y/n:" << endl;
        cin >> replay;
    } while (replay == "y" || replay == "yes");

    return 0;
}