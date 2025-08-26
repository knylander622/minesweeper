#include <iostream>
#include <vector>
using namespace std;
struct Cell
{
    bool mine;
    bool revealed;
    bool flagged;
    int surroundingMines;

    Cell(bool m, bool r, bool f, int sM)
    {
        mine = m;
        revealed = f;
        flagged = f;
        surroundingMines = sM;
    }
};

int main()
{
 vector<vector<Cell>> board;
}