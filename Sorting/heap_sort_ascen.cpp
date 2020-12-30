// implementation of heap sort algorithm , in ascending order.

#include <iostream>
#include <utility> // for swap function
using namespace std;

void heapify(int arr[], int size, int i) // to maintain max_heap
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void build_max_heap(int arr[], int size) // to build max_heap
{
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

void heap_sort(int arr[], int size)
{
    build_max_heap(arr, size);

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int size;
    cout << "\nenter number of elements in the array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart Your Array : \n";
    for(int i=0; i<size; i++)
    {
        cout << i+1 << "). " ;
        cin >> arr[i];
    }

    heap_sort(arr, size);

    cout << "\nAfter Sorting : ";
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";

    return 0;
}