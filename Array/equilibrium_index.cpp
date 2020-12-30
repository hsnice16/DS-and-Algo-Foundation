/*
    Description - Equilibrium index of an array is an index such 
    that the sum of elements at lower indexes is equal to the sum 
    of elements at higher indexes. We are given an Array of integers, 
    We have to find out the first index i from left such that -
    
    A[0] + A[1] + ... A[i-1] = A[i+1] + A[i+2] ... A[n-1]
    
    Input
    [-7, 1, 5, 2, -4, 3, 0]
    Output
    3
    A[0] + A[1] + A[2] = A[4] + A[5] + A[6]
*/
#include <iostream>
using namespace std;

int equilibrium_ind(int arr[], int size)
{
    int sum = 0;
    int left_sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    for (int i = 0; i < size; i++)
    {
        sum -= arr[i];
        if (sum == left_sum)
            return i;
        left_sum += arr[i];
    }

    return -1;
}

int main()
{
    int size;
    cout << "\nWhat's the size of the array ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int equ_ind = equilibrium_ind(arr, size);
    cout << "\nequilibrium index : " << equ_ind;

    return 0;
}