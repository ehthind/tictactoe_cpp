using namespace std;
#include <iostream>

class Board {   
    private:
    string board[9];

    public:
    Board();
    string getValueAtPosition(int);
    void updateBoard(int, string);
    void ToString();
};
