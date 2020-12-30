/*
    Description : We are given an array of positive and negative integers. 
    We have to find the subarray having maximum sum.
    Input
    [-3, 4, -1, -2, 1, 5]
    Output
    7
    (4+(-1)+(-2)+1+5)
*/

#include <iostream>
using namespace std;

// function finding subarray having maximum sum
// and length of that subarray and its elements
void max_sum(int arr[], int size)
{
    int max_sum = 0;
    int curr_sum = 0;
    int start = 0;
    int end = 0;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        curr_sum += arr[i];

        if (max_sum < curr_sum)
        {
            max_sum = curr_sum;
            start = temp + 1;
            end = i;
        }

        if (curr_sum < 0)
        {
            temp = i;
            curr_sum = 0;
        }
    }

    cout << "\nsub array having maximum sum : " << max_sum;
    cout << "\nsub array elements : ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";

    return;
}

int main()
{
    int size;
    cout << "\nWhat's the size of array ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    max_sum(arr, size);

    return 0;
}