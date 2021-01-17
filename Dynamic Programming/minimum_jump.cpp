/*
    Implementation of Minimum Jumps to Reach End problem
*/
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

/*
// function finding min jumps , we have to make to reach the end
int minJumps(int arr[], int size)
{
    if (size == 1)
        return 0;

    int res = INT_MAX;
    for (int i = 0; i <= (size - 2); i++)
    {
        if (i + arr[i] >= (size - 1))
        {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}
*/
// DP version
int minJumps(int arr[], int size)
{
    int table[size]; /* table[i] -> min jumps to reach index i in given array */
    table[0] = 0;    // base case

    fill(table + 1, table + size, INT_MAX); // initialize rest value as infinite

    // traverse the array
    for (int i = 1; i < size; i++)
    {
        // min jumps to reach this index from elements on left of it
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i)
            {
                if (table[j] != INT_MAX)
                {
                    table[i] = min(table[i], table[j] + 1);
                }
            }
        }
    }

    return table[size - 1];
}

int main()
{
    int size; // array size containing values(indicating jumps)
    cout << "\nEnter size of the array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart entering values in array : ";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    cout << "\nMinimum number of jumps required to reach the end : " << minJumps(arr, size);

    return 0;
}