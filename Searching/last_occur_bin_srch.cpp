// Implementation of problem, to find last occurence of
// given value in sorted array, it exists

#include <iostream>
using namespace std;

// finding last occurence of value in sorted array arr, if it exist
int last_occur_bin_srch(int arr[], int size, int value)
{
    int low = 0;
    int high = size - 1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value)
        {
            if (mid != (size-1) && arr[mid + 1] == arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] > value)
        {
            high = mid - 1;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your sorted array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int value;
    cout << "\nenter value of which first occurence to find : ";
    cin >> value;

    int last_ind = last_occur_bin_srch(arr, size, value);

    if (last_ind != -1)
    {
        cout << "\nlast occurence of " << value << " in sorted given array : "
             << last_ind;
    }
    else
    {
        cout << "\n"
             << value << " doesn't exist in given array .";
    }

    return 0;
}