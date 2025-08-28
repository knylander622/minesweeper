#include "board.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

Cell::Cell(): mine(false), revealed(false), flagged(false), surroundingMines(0) {}

void generateBoard(int r, int c, vector<vector<Cell>>&board)
{
board.resize(r,vector<Cell>(c));
}

void generateMines(int r, int c, int m, vector<vector<Cell>>&board)
{
    default_random_engine engine(time(0));
    int t = r * c;
    vector<int>spots(t);
    for(int i = 0; i < t; i++)
    {
        spots[i] = i;
    }

    shuffle(spots.begin(),spots.end(), engine);

    for (int i = 0; i < m; i++)
    {
        int pos = spots[i];
        int row = pos / c;
        int cols = pos % c;
        board[row][cols].mine = true;
    }
}

void findNearbyMines(int r, int c, vector<vector<Cell>>&board)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int count = 0;

            for (int sr = -1; sr <= 1; sr++)
            {
                for (int sc = -1; sc <= 1; sc++)
                {
                    if (sr == 0 && sc == 0)
                        continue;

                    int ni = i + sr;
                    int nj = j + sc;

                    // Check if neighbor indices are in bounds
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                    {
                        if (board[ni][nj].mine)
                        {
                            count++;
                        }
                    }
                }
            }

            board[i][j].surroundingMines = count;
            if(count == 0)
            {
            }
        }
    }
}

void printBoard(int r, int c, vector<vector<Cell>>&board)
{
    cout << "   ";
    for(int i = 1; i < c + 1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(j == 0)
                cout << (char('A' + i)) << ": ";
            if(board[i][j].revealed)
            {
                string surround = to_string(board[i][j].surroundingMines) + " ";
                cout << (board[i][j].mine ? "* " : surround);
            }
            else
            {
                cout << "# ";
            }
        }
        cout << endl;
    }
}

void updateBoard(string choice,int ro, int co, vector<vector<Cell>>&board)
{
    char r = choice[0];
    string c = choice.substr(1,1);

    int col = stoi(c);
    int counter = 0;
    while(r != 'A')
    {
        r -= 1;
        counter++;
    }

    board[counter][col - 1].revealed = true;
}

void playGame(int rows,int cols, int mines, vector<vector<Cell>>&board)
{
    bool play = true;
    string choice;
    generateBoard(rows, cols, board);
    generateMines(rows, cols, mines, board);
    findNearbyMines(rows, cols, board);

    while(play)
    {
        printBoard(rows, cols, board);
        cout << endl << "Enter your choice:" << endl;
        cin >> choice;
        while(choice.length() != 2)
        {
            cout << "Error: Improper choice format. Model after example A1" << endl;
            cin >> choice;
        }
        updateBoard(choice, rows, cols, board);
    }
}