/*
    Implementation of finding longest increasing subsequence problem.

    I/P : {1, 2, 3}
    subsequences possible : {}, {1}, {2}, {3}, {1,2} , {1,3}, {2,3}, {1,2,3}
    O/P : 3
    as {1,2,3} has all entries in increasing order and it is the longest.
*/
#include <algorithm>
#include <iostream>
using namespace std;

/*

    function finding maximum LIS :
        Time complexity = theta(n^2)
        Auxiliary space = theta(n)

int lis(int arr[], int size)
{
    int lis_arr[size];        // array will contain length of LIS possible for every element
    fill_n(lis_arr, size, 1); // initialize all the value in lis_arr with 1, as every element has 1 LIS

    for (int i = 1; i < size; i++) // start from second element
    {
        for (int j = 0; j < i; j++) // traverse the value on left of it
        {
            if (arr[j] < arr[i])
                lis_arr[i] = max(lis_arr[i], lis_arr[j] + 1);
        }
    }
    return *max_element(lis_arr, lis_arr + size);
}
*/

// function index of lowest ceil value of val
int ceilIdx(int tail[], int start, int end, int val)
{
    while (end > start)
    {
        int m = start + (end - start) / 2;
        if (tail[m] >= val)
        {
            end = m;
        }
        else
        {
            start = m + 1;
        }
    }
    return end;
}

/*
    function finding LIS with
        time complexity : O(nlogn)
*/
int lis(int arr[], int size)
{
    int tail[size]; // tail[i] stores the min possible tail for LIS of length(i+1)
    int len = 1;    // number of elements currently present in tail
    tail[0] = arr[0];

    for (int i = 1; i < size; i++) // traverse the arr
    {
        if (arr[i] > tail[len - 1]) // simple append in tail
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilIdx(tail, 0, len - 1, arr[i]); // lowest ceil value in tail, using binary search
            tail[c] = arr[i];                          // replace value at c in tail with value at i in arr
        }
    }
    return len;
}

int main()
{
    int size;
    cout << "\nEnter size of the array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    cout << "\nSize of longest increasing subsequence : " << lis(arr, size) << endl;

    return 0;
}