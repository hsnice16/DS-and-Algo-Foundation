/*
    Implementation of Sudoku Problem.

    We have given a partial filled grid. And we have to fill empty
    cells.
*/
#include <cmath>
#include <iostream>
using namespace std;

#define N 4

bool isSafe(int i, int j, int n, int grid[][N])
{
    // check row and column
    for (int k = 0; k < N; k++)
    {
        if (grid[k][j] == n || grid[i][k] == n)
            return false;
    }

    // in grid of size SQUARE_ROOT of N
    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;

    // check in smaller grid
    for (int m = 0; m < s; m++)
    {
        for (int p = 0; p < s; p++)
        {
            if (grid[m + rs][p + cs] == n)
                return false;
        }
    }
    return true;
}

bool solvable(int grid[][N])
{
    int i, j;
    bool cont = true;

    // find first empty cell
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                cont = false;
                break;
            }
        }
        if (!cont)
        {
            break;
        }
    }

    // if there are no empty cell
    if (i == N && j == N)
        return true;

    for (int n = 1; n <= N; n++)
    {
        if (isSafe(i, j, n, grid))
        {
            grid[i][j] = n;
            if (solvable(grid))
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

void printGrid(int grid[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    // 0 represents empty cells
    int grid[N][N] = {
        {1, 0, 3, 0},
        {0, 0, 2, 1},
        {0, 1, 0, 2},
        {2, 4, 0, 0}};

    if (solvable(grid))
    {
        cout << "\nSolved Sudoku : \n";
        printGrid(grid);
    }
    else
    {
        cout << "\nSudoku is not solvable !!\n";
    }

    return 0;
}