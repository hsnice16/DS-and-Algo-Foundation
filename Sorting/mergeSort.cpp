// Implementation of merge sort algorithm

#include <iostream>
using namespace std;

// merge two sorted halves of an array
void merge(int arr[], int start_ind, int mid_ind, int last_ind)
{
    int size1 = mid_ind - start_ind + 1;
    int size2 = last_ind - mid_ind;

    int left[size1];
    int right[size2];

    for (int i = 0; i < size1; i++)
        left[i] = arr[start_ind + i]; // start_ind can have any value,
                                      // similar goes for mid_ind and last_ind

    for (int j = 0; j < size2; j++)
        right[j] = arr[mid_ind + 1 + j];

    int i = 0, j = 0;
    int index = start_ind;

    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
            arr[index++] = left[i++];
        else
            arr[index++] = right[j++];
    }

    while (i < size1)
        arr[index++] = left[i++];

    while (j < size2)
        arr[index++] = right[j++];
}

void merge_sort(int arr[], int start_ind, int last_ind)
{
    if (last_ind > start_ind) // atleast there should be two elements
    {
        int mid_ind = start_ind + (last_ind - start_ind) / 2; // to avoid overflow
        merge_sort(arr, start_ind, mid_ind);
        merge_sort(arr, mid_ind + 1, last_ind);
        merge(arr, start_ind, mid_ind, last_ind); // merge the storted part
    }
}

int main()
{
    int size;
    cout << "\nenter number of elements in your array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : ";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int start_ind = 0;
    int last_ind = size - 1;

    merge_sort(arr, start_ind, last_ind);

    cout << "\nAfter sorting :";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}