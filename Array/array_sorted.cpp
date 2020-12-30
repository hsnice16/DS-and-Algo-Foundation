// Implementation of problem, checking array is sorted in non-decreasing
// order or not.

#include <iostream>
using namespace std;

bool sorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
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

    if (sorted(arr, size))
        cout << "\nArray is sorted in non-decreasing order !!\n";
    else
        cout << "\nArray is not sorted in non-decreasing order !!\n";

    return 0;
}