// naive parition for quick sort algorithm

#include <iostream>
using namespace std;

// naive parition
void naive_partition(int arr[], int start_ind, int end_ind, int pivot)
{
    int temp[end_ind - start_ind + 1]; // temporary array
    int index = 0;

    // value less than equal to value at pivot index
    for (int i = start_ind; i <= end_ind; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            temp[index++] = arr[i];
        }
    }

    // value greater than value at pivot index
    for (int i = start_ind; i <= end_ind; i++)
    {
        if (arr[i] > arr[pivot])
        {
            temp[index++] = arr[i];
        }
    }

    // copying back the temporary array in original array
    for (int i = start_ind; i <= end_ind; i++)
    {
        arr[i] = temp[i];
    }

    return;
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

    // assuming pivot value, we are deciding pivot value
    int pivot = size - 1; // should be a valid index

    int start_ind = 0;
    int end_ind = size - 1;

    naive_partition(arr, start_ind, end_ind, pivot);

    cout << "\nAfter naive parition : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}