// quick sort implementation, using lomuto partitioning method

#include <iostream>
using namespace std;

// swap function
void swap(int &num_1, int &num_2)
{
    int temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}

// lomuto partition
int lomuto_partition(int arr[], int start_ind, int end_ind)
{
    // we assuming , pivot value is last value of array
    int pivot = arr[end_ind];

    /*
        if we take a valid pivot value index from user
        than we can first swap the value at given index 
        with last value of the array and work with this
        function
    */

    int ind = start_ind-1; // index of lowest value than pivot

    for (int i = start_ind; i <= (end_ind - 1); i++)
    {
        if (arr[i] < pivot)
        {
            ind++;
            swap(arr[ind], arr[i]);
        }
    }

    // for positioning pivot value at correct index
    swap(arr[ind + 1], arr[end_ind]);

    return ind + 1;
}

void quick_sort(int arr[], int start_ind, int end_ind)
{
    if (start_ind < end_ind) // there should be two elements, to sort
    {
        int pivot_ind = lomuto_partition(arr, start_ind, end_ind);
        // cout << endl << pivot_ind << endl ;
        quick_sort(arr, start_ind, pivot_ind - 1);
        quick_sort(arr, pivot_ind + 1, end_ind);
    }
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

    int start_ind = 0;      // starting index
    int end_ind = size - 1; // ending or last index

    // lomuto_partition(arr, start_ind, end_ind);

    /*
    cout << "\nAfter partitioning : ";
    for(int i=0; i<size;i++)
    {
        cout << arr[i] << " ";
    }
    */

    quick_sort(arr, start_ind, end_ind);

    cout << "\nAfter sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}