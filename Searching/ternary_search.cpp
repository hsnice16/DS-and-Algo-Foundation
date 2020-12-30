// Implementation of ternary search

#include <iostream>
#include <algorithm>
using namespace std;

int ternary_search(int arr[], int size, int val)
{
    int low = 0, high = size - 1;

    while (high >= low)
    {
        int mid_1 = low + (high - low) / 3;
        int mid_2 = high - (high - low) / 3;

        if (arr[mid_1] == val)
            return mid_1;
        else if (arr[mid_2] == val)
            return mid_2;
        else if (arr[mid_1] > val)
            high = mid_1 - 1;
        else if (arr[mid_2] < val)
            low = mid_2 + 1;
        else
        {
            low = mid_1 + 1;
            high = mid_2 - 1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int value;
    cout << "\nenter value to search : ";
    cin >> value;

    sort(arr, arr + size); // ternary search works on sorted array

    int ind = ternary_search(arr, size, value);

    cout << "\nSorted List : ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    if (ind != -1)
        cout << value << " is present at index " << ind;
    else
        cout << value << " is not present in given array.";

    return 0;
}