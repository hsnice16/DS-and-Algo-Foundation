// program to find given value is present in the array or not

#include <iostream>
using namespace std;

bool search_value(int arr[], int start_ind, int end_ind, int value)
{
    if (start_ind > end_ind)
        return false;
    else if (arr[start_ind] == value)
        return true;
    else if (arr[end_ind] == value)
        return true;
    return search_value(arr, start_ind + 1, end_ind - 1, value);
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

    int value;
    cout << "\nWhich value to search ?(enter): ";
    cin >> value;

    int start_ind = 0;
    int end_ind = size - 1;

    cout << endl;
    if (search_value(arr, start_ind, end_ind, value))
        cout << value << " is present in given array .\n";
    else
        cout << value << " is not present in given array .\n";

    return 0;
}