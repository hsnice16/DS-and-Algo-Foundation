
// Problem Description : We are given an Array of n integers, We are given q queries
// having indices l and r . We have to find out sum between the given range of indices.

#include <iostream>
using namespace std;

void solve_queries(int arr[], int size)
{
    int prefix_sum[size] = {0}; // prefix sum array
    prefix_sum[0] = arr[0];
    for (int i = 1; i < size; i++) // calculating prefix sum
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int q, l, r;
    cout << "\nenter number of queries you have : ";
    cin >> q;

    for(int i=0;i<q;i++)
    {
        cout << "\n\nQuery 1";
        cout << "\nenter 'l' value : ";
        cin >> l;
        cout << "enter 'r' value : ";
        cin >> r;

        cout << "\nSum : ";
        if(l == 0)
            cout << prefix_sum[r];
        else
            cout << prefix_sum[r] - prefix_sum[l-1];
    }
}

int main()
{
    int size;
    cout << "\nWhat's the size of the array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    solve_queries(arr, size);

    return 0;
}