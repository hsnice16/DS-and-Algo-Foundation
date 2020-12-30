// Implementation of left rotate an array by one

#include <iostream>
using namespace std;

void left_rotate(int arr[], int size)
{
    int temp = arr[0];
    for (int i=1; i<size ;i++)
        arr[i-1] = arr[i];
    arr[size-1] = temp;
}

int main()
{
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};

    left_rotate(arr, size);

    cout << "\nOutput : ";
    for(int i=0; i<size ;i++)
        cout << arr[i] << " ";

    return 0;
}