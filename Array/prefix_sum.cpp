// Implementation of problem Finding sum in Range
/*
    Sample Problem: Consider an array of size N with all initial values as 0.
    Perform given 'm' add operations from index 'a' to 'b' and evaluate highest
    element in array. 
    An add operation adds 100 to all elements from index a to b (both inclusive).

    Example:
    Input : n = 5 // We consider array {0, 0, 0, 0, 0}
            m = 3.
            a = 2, b = 4.
            a = 1, b = 3.
            a = 1, b = 2.
    Output : 300

    Explanation : 
    After I operation -
    A : 0 100 100 100 0

    After II operation -
    A : 100 200 200 100 0

    After III operation -
    A : 200 300 200 100 0

    Highest element : 300
*/

// Solution using prefix sum

#include <iostream>
#include <algorithm>
using namespace std;

int highest_element(int arr[], int size, int a_b_val[][2], int add_ope)
{
    for (int i = 0; i < add_ope; i++)
    {
        if (a_b_val[i][0] > 0 && a_b_val[i][1] <= size)
        {
            arr[a_b_val[i][0] - 1] += 100;
            arr[a_b_val[i][1]] += -100;
        }
    }

    // calculating prefix sum of arr
    for (int i = 1; i < size; i++)
    {
        arr[i] += arr[i - 1];
    }

    return *max_element(arr, arr + size);
}

int main()
{
    int size;
    cout << "\nWhat's the size of array ?(enter): ";
    cin >> size;

    int arr[size] = {0};

    int add_ope; // number of add operations
    cout << "\nHow many add operations to perform ?(enter) : ";
    cin >> add_ope;

    int a_b_val[add_ope][2];
    for (int i = 0; i < add_ope; i++)
    {
        cout << "\nenter 'a' value : ";
        cin >> a_b_val[i][0];
        cout << "enter 'b' value : ";
        cin >> a_b_val[i][1];
    }

    int high_val = highest_element(arr, size, a_b_val, add_ope);
    cout << "\nHighest element in array : " << high_val;

    return 0;
}