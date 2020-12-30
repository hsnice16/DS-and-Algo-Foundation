/*
    Problem:
    Given an unsorted array of size n. Array elements are in the
    range from 1 to n. One number from set {1, 2, ...n} is missing
    and one number occurs twice in the array. Our task is to find
    these two numbers
    Sample Input
    [2, 3, 2, 1, 5]
    Sample Output
    4 2
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// finding value of missing and repeating element
void missing_n_repeating(int arr[], int size)
{
    int repeating_val;

    for (int i = 0; i < size; i++) // traversing array
    {
        int temp = arr[abs(arr[i]) - 1]; // element of array as index

        if (temp < 0) // checking if already negative, means visited
            repeating_val = abs(arr[i]);
        else
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; // marking negative, means visited
    }
    int missing_val;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            missing_val = i + 1;
    }

    cout << "\nMissing value : " << missing_val;
    cout << "\nRepeating value : " << repeating_val;

    return;
}

int main()
{
    int size;
    cout << "\nwhat's the size of array ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array(should contain only value [1, size]: \n";
    for(int i=0; i<size; i++)
    {
        cout << i+1 << "). ";
        cin >> arr[i];
    }

    missing_n_repeating(arr, size);

    return 0;
}