// Implementation of problem, find largest element
// of the array

#include <iostream>
using namespace std;

int largest_ind(int arr[], int size)
{
    int largest = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[largest])
            largest = i;
    }
    return largest;
}

int main()
{
    int size;
    cout << "\nWhat's the size of array ?(enter) : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int ind = largest_ind(arr, size); // largest value index
    cout << "\nLargest value in array : " << arr[ind] << endl;

    return 0;
}