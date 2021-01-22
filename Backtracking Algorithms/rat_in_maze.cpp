/*
    Description : we have given a binary matrix, which represents a maze.
                    0's value in this matrix are blocked cells and 1's value are
                    free cells. A rat is present at top left corner and a cheese 
                    is at bottom right corner.
    Problem : Rat has to collect cheese. And rat can go only from free cells.

    Constraints : Only two moves allowed from (i,j)
                    1) (i+1, j) , cell just below it
                    2) (i, j+1), cell just on right of it
*/
#include <iostream>
using namespace std;

// #define ROW 4
// #define COL 4

/*
    naive approach

// function finding Is rat can take the cheese or not
bool take_cheese(int maze[][COL], int start_r, int start_c)
{
    if (start_r == (ROW - 1) && start_c == (COL - 1))
        return true;

    if (maze[start_r + 1][start_c] == 1)
        return take_cheese(maze, start_r + 1, start_c);
    else if (maze[start_r][start_c + 1] == 1)
        return take_cheese(maze, start_r, start_c + 1);

    return false;
}
*/

int N = 4;
int maze[4][4] = { // 2-d array representing array
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}};
int sol[4][4];

// present in almost every backtracking algo
bool isSafe(int i, int j) // move is safe or not
{
    return (i < N && j < N && maze[i][j] == 1);
}

bool solveMaze(int i, int j)
{
    if (i == (N - 1) && j == (N - 1))
    {
        sol[i][j] = 1;
        return true;
    }
    if (isSafe(i, j) == true)
    {
        sol[i][j] = 1;
        if (solveMaze(i + 1, j) == true)
            return true;
        else if (solveMaze(i, j + 1))
            return true;
        sol[i][j] = 0;
    }
    return false;
}

void printSol()
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << ' ';
        }
        cout << endl;
    }
}

bool take_cheese()
{
    if (solveMaze(0, 0) == false)
        return false;
    else
    {
        printSol();
        return true;
    }
}

int main()
{
    if (take_cheese())
        cout << "\nRat can eat the cheese.\n";
    else
        cout << "\nRat can not eat the cheese.\n";
    return 0;
}