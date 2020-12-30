// Implementation of problem, finding second
// largest element of array

#include <iostream>
using namespace std;

int second_largest(int arr[], int size)
{
    int res = -1, largest = 0;
    for(int i=1; i<size; i++)
    {
        if(arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] < arr[largest])
        {
            if(res == -1)       // if no second largest exist
            {
                res = i;
            }
            else if(arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int size;
    cout << "\nWhat's the size of the array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for(int i=0; i<size; i++)
    {
        cout << i+1 << "). ";
        cin >> arr[i];
    }

    int ind = second_largest(arr, size);

    if(ind != -1)
        cout << "\nSecond largest element : " << arr[ind] << endl;
    else
        cout << "\nThere is no second largest element !!\n";

    return 0;
}