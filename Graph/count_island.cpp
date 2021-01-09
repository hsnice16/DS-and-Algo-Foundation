/*
    Description - Given a boolean 2D matrix, find the number of islands.
                    A group of connected 1s forms an island. For example, the below
                    matrix contains 5 islands

    A group of connected 1s forms an island.
*/

/*
    Given :
            {{1, 1, 0, 0, 0},
             {0, 1, 0, 0, 1},
             {1, 0, 0, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 0, 1, 0, 1},}
*/

#include <iostream>
using namespace std;

#define row 5
#define col 5

// check for next call
bool call(int adj_mtx[][col], int r, int c, bool visited[][col])
{
    return ((r >= 0) && (r < row) && (c >= 0) && (c < col) && (adj_mtx[r][c]) && (!visited[r][c]));
}

// dfs traversal
void dfs(int adj_mtx[][col], int r, int c, bool visited[][col])
{
    // to find 8 adjacent (or neighbours) of a given cell
    int add_row[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // add in row number
    int add_col[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // add in column number

    visited[r][c] = true;

    // for 8 adjacent
    for (int adj = 0; adj < 8; adj++)
    {
        if ((call(adj_mtx, r+add_row[adj], c+add_col[adj], visited)) == true)
            dfs(adj_mtx, r + add_row[adj], c + add_col[adj], visited);
    }
}

// count island
int countIslands(int adj_mtx[][col])
{
    bool visited[row][col] = {false};
    int count = 0;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if ((adj_mtx[r][c] != 0) && (visited[r][c] == false))
            {
                count++;
                dfs(adj_mtx, r, c, visited);
            }
        }
    }
    return count;
}

int main()
{
    int adj_mtx[row][col] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1},
    };

    cout << "\nNumber of Islands : " << countIslands(adj_mtx);

    return 0;
}