/*
    Description - Given a matrix of dimension m*n where each cell in the
                    matrix can have values 0, 1 or 2 which has the following 
                    meaning:

        0 : Empty cell
        1 : Cells have fresh oranges
        2 : Cells have rotten oranges

    Problem :  Determine what is the minimum time required so that all oranges
                become rotten . A rotten orange at index[i,j] can rot other fresh
                orange at indexes [i-1,j], [i+1, j], [i,j-1], [i, j+1] and If it 
                is impossible to rot every orange then simply return -1.
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define row 3
#define col 5

// check indexes are valid or not
bool isvalid(int a, int b)
{
    return ((a >= 0) && (a < row) && (b >= 0) && (b < col));
}

// check if p is delimiter
bool isdelim(pair<int, int> p)
{
    return ((p.first == -1) && (p.second == -1));
}

int count_time_frame(int arr[row][col])
{
    queue<pair<int, int>> q; // an empty Q for storing cell

    // storing all cells with rotten oranges
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (arr[r][c] == 2)
                q.push(make_pair(r, c));

    if (q.empty()) // if no oranges are rotten
        return -1;

    q.push(make_pair(-1, -1)); // to show end of time frame
    int count_time = 0;        // to count time frame

    while (!q.empty())
    {

        bool flag = false; // check the first fresh orange , getting orange

        // till end of time frame reach
        while (!isdelim(q.front()))
        {

            pair<int, int> curr = q.front();
            q.pop();

            // check adjacents
            if (isvalid(curr.first - 1, curr.second) && arr[curr.first - 1][curr.second] == 1)
            {
                if (!flag) // check if it is first new rotten orange
                {
                    count_time++;
                    flag = true;
                }
                arr[curr.first - 1][curr.second] = 2;
                curr.first--; // move to adjacent cell
                q.push(curr); // push in queue
                curr.first++; // move back to original cell
            }
            if (isvalid(curr.first + 1, curr.second) && arr[curr.first + 1][curr.second] == 1)
            {
                if (!flag) // check if it is first new rotten orange
                {
                    count_time++;
                    flag = true;
                }
                arr[curr.first + 1][curr.second] = 2;
                curr.first++; // move to adjacent cell
                q.push(curr); // push in queue
                curr.first--; // move back to original cell
            }
            if (isvalid(curr.first, curr.second - 1) && arr[curr.first][curr.second - 1] == 1)
            {
                if (!flag) // check if it is first new rotten orange
                {
                    count_time++;
                    flag = true;
                }
                arr[curr.first][curr.second - 1] = 2;
                curr.second--; // move to adjacent cell
                q.push(curr);  // push in queue
                curr.second++; // move back to original cell
            }
            if (isvalid(curr.first, curr.second + 1) && arr[curr.first][curr.second + 1] == 1)
            {
                if (!flag) // check if it is first new rotten orange
                {
                    count_time++;
                    flag = true;
                }
                arr[curr.first][curr.second + 1] = 2;
                curr.second++; // move to adjacent cell
                q.push(curr);  // push in queue
            }
        }

        q.pop();        // pop the delimiter
        if (!q.empty()) // if queue is not empty
        {
            q.push(make_pair(-1, -1));
        }
    }

    // if all oranges are not rotten
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (arr[r][c] != 2 && arr[r][c] != 0)
                return -1;

    return count_time;
}

int main()
{

    int arr[row][col] = {{2, 1, 0, 2, 1},
                         {1, 0, 1, 2, 1},
                         {1, 0, 0, 2, 1}};

    int time = count_time_frame(arr);
    if (time != -1)
    {
        cout << "\nAll oranges can become rotten in " << time << " time frames.\n";
    }
    else
    {
        cout << "\nAll oranges cannot be rotten.\n";
    }

    return 0;
}