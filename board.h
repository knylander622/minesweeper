#ifndef BOARD_H
#define BOARD_H
#include <vector>
using namespace std;
struct Cell
{
    bool mine;
    bool revealed;
    bool flagged;
    int surroundingMines;

    Cell();
};

void playGame(int rows, int cols, int mines, vector<vector<Cell>>&board);
void generateBoard(int rows, int cols, vector<vector<Cell>>&board);
void generateMines(int rows,int cols,int mines, vector<vector<Cell>>&board);
void findNearbyMines(int rows, int cols, vector<vector<Cell>>&board);
void printBoard(int rows, int cols, vector<vector<Cell>>&board);

#endif