// quick sort implementation, using hoare's parition

#include <iostream>
using namespace std;

// swap function
void swap(int &num_1, int &num_2)
{
    int temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}

// hoare's parition
int hoare_partition(int arr[], int start_ind, int end_ind) // returns the index, left of which
// (including itself) are smaller (or equal) than pivot value and right of which (excluding itself) are
// larger or equal to pivot value
{
    int pivot = arr[start_ind]; // first value of array

    int low = start_ind - 1;
    int high = end_ind + 1;

    while (true)
    {
        do
        {
            low++;
        } while (arr[low] < pivot);

        do
        {
            high--;
        } while (arr[high] > pivot);

        if (low >= high)
            return high;

        swap(arr[low], arr[high]);
    }
}

void quick_sort(int arr[], int start_ind, int end_ind)
{
    if (start_ind < end_ind)
    {
        int pivot_ind = hoare_partition(arr, start_ind, end_ind);
        quick_sort(arr, start_ind, pivot_ind);
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

    /*
    hoare_partition(arr, start_ind, end_ind);

    cout << "\nAfter partitioning : ";
    for (int i = 0; i < size; i++)
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