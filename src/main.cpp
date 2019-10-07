
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Board {
    protected:
    string board[9];
    
    public:
    Board() {
        for(int i = 0; i < 9; i ++ ) {
            this -> board[i] = to_string(i+1);
        }
    }

    void ToString() {
        for(int i = 0; i < 9; i ++ ) {
            cout << ' ' << this -> board[i];
            if (i != 2 && i != 5 && i != 8) {
                cout << ' ' << '|';
            } else if (i == 2 || i == 5 || i == 8) { 
                const string rowDivider = "---+---+---";
                cout << endl << rowDivider << endl;
            }
        }
    };
};

int main() {
    Board ticTacToe;
    ticTacToe.ToString();

    return 0;
}