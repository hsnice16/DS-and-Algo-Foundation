/*
   Description - We are given an array of distinct integers.
   We have to find the peak element ( The element which is
   greater than both the neighbours ). There can be many such
   elements we need to return any of them.

   Input : [10, 20, 15, 2, 23, 90, 67]
   Output : 20 or 90
*/

#include <iostream>
using namespace std;

// finding peak element in given array
int find_peak_ele(int arr[], int size)
{
    int low = 0;
    int high = size-1;

    while(high >= low)
    {
        int mid = low + (high-low)/2;

        if ((mid == 0 || arr[mid-1] <= arr[mid]) && 
            (mid == (size-1) || arr[mid] >= arr[mid+1]))
        {
            return arr[mid];
        }
        else if(mid > 0 && arr[mid-1] > arr[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "\nwhat's the size of array ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for(int i=0; i<size; i++)
    {
        cout << i+1 << "). ";
        cin >> arr[i];
    }

    int val = find_peak_ele(arr, size);
    cout << "\nOne peak element of array is : " << val;

    return 0;
}