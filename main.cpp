
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Board {
    protected:
        string board[9];
    public:
        Board();
        void ToString() {
            for(int i = 0; i < 9; i ++ ){
                cout << ' ' << this -> board[i];
                if (i != 2 && i != 5 && i != 8) {
                    cout << ' ' << '|';
                }
                if (i == 2 || i == 5 || i == 8) { 
                    cout << endl;
                    cout << '-' << '-' << '-' << '+' << '-' << '-' << '-' << '+' << '-' << '-' << '-';
                    cout << endl;
                }
            }
        };
};

Board::Board() {
    for(int i = 0; i < 9; i ++ ){
        this -> board[i] = to_string(i+1);
    }
};

int main() {
    Board ticTacToe;
    ticTacToe.ToString();

    return 0;
}