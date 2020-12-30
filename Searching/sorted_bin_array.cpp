// Implementation of problem, to count total occurence
// of 1's in sorted binary array

#include <iostream>
using namespace std;

// counting total occurence of 1's
int times_one_occur(int arr[], int size)
{
    int low = 0;
    int high = size - 1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1)
        {
            if (mid != 0 && arr[mid - 1] == 1)
            {
                high = mid - 1;
            }
            else
            {
                return size-mid;
            }
        }
        else if (arr[mid] == 0)
        {
            low = mid+1;
        }
    }

    return 0;
}

int main()
{
    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your sorted binary array : \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int total_occurence = times_one_occur(arr, size);

    cout << "\nTotal number of times 1's occurs in given sorted binary array : "
         << total_occurence ;

    return 0;
}