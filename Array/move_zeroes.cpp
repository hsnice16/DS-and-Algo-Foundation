// Implementation of problem, moving all zeroes at the end of array

#include <iostream>
#include <utility>
using namespace std;

void move_zeroes(int arr[], int size)
{
    int count = 0;  // count of non-zero terms

    for (int i=0; i<size; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
}

int main()
{
    int size;
    cout << "\nenter size of the array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i=0; i<size; i++)
    {
        cout << i+1 << "). ";
        cin >> arr[i];
    }

    move_zeroes(arr, size);

    cout << "\nAll zeroes are at the end : ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}