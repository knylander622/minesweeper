#include "board.h"
#include <iostream>
using namespace std;
int main()
{
int rows, cols, mines;
vector<vector<Cell>> board;
 
cout << "Enter dimensions and mines" << endl;
cin >> rows >> cols >> mines;

while(rows * cols < mines)
{
    cout << "Error: Mines exceed total squares. Try again please." << endl;
    cin >> rows >> cols >> mines;
}

playGame(rows, cols, mines, board);

}