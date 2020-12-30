// Implementation of problem,
// maximum sum of k consecutive elements
// of array

#include <iostream>
using namespace std;

// finding maximum sum of k consecutive elements
int maximum_sum(int arr[], int size, int k)
{
    int sum = 0;
    int temp_sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (i < k)
        {
            sum += arr[i];
            temp_sum += arr[i];
        }
        else
        {
            temp_sum += arr[i] - arr[i-k];
            if (temp_sum > sum)
                sum = temp_sum;
        }
    }
    return sum;
}

int main()
{
    int size;
    cout << "\nWhat's size the array ?(enter): ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    int k;
    cout << "\nSum of how many consecutive elements ?(enter): ";
    cin >> k;

    if (k > size)
        cout << "\nnumber of consecutive elements are greater than size of array.\n"
             << "It should be less than size of array.";
    else
    {
        int max_sum = maximum_sum(arr, size, k);
        cout << "\nMaximum sum : " << max_sum << endl;
    }
    return 0;
}