/*
    N - Queen Problem

    Description : Given a value N , check we can palce N queens on a 
    N x N chess board , such that no queen attacks each other Or we 
    cannot place. 

    Super Naive Solution : Generate all (n^2) C (n) combinations
    Naive Solution : Generate all permutations of row numbers(0 to N-1)
    Backtracking : Work on same idea of Naive Solution, But cut down the
                    recursion tree as soon as we find infeasibility.
*/
#include <iostream>
using namespace std;

#define N 8

bool isSafe(int row, int col, int sol[][N])
{
    // check in row
    for (int i = 0; i < col; i++)
        if (sol[row][i])
            return false;

    // check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (sol[i][j])
            return false;

    // check lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (sol[i][j])
            return false;

    return true;
}

// solve, by generating permutation
bool solve(int sol[][N], int col)
{
    if (col == N)
        return true;

    for (int row = 0; row < N; row++)
    {
        if (isSafe(row, col, sol))
        {
            sol[row][col] = 1;
            if (solve(sol, col + 1))
                return true;
            sol[row][col] = 0;
        }
    }
    return false;
}

// check we can place or not
bool canPlace(int sol[][N])
{
    if (solve(sol, 0) == false)
        return false;
    else
        return true;
}

// traversing the sol array
void printSol(int sol[][N])
{
    cout << "\nChess Board : \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int sol[N][N] = {0};

    if (canPlace(sol))
    {
        cout << "\nWe can place queens.\n";
        printSol(sol);
    }
    else
    {
        cout << "\nWe cannot place queens .\n";
    }

    return 0;
}