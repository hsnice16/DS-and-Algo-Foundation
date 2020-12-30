// implementation of bucket sort algorithm

// assuming , we are taking bucket no. from user, and numbers are positive integers
 
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucket_sort(int arr[], int size, int bucket_n)
{
    int max = *max_element(arr, arr + size); // finding maximum element in input array
    max++;
    vector<int> bucket[bucket_n]; // making array , representing buckets

    // putting element of array in corresponding bucket
    for (int i = 0; i < size; i++)
    {
        int b = (bucket_n * arr[i]) / max;      // index for bucket array
        bucket[b].push_back(arr[i]);
    }

    // sorting elements in each bucket
    for (int i = 0; i < bucket_n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    // joining buckets
    int index = 0;
    for (int i = 0; i < bucket_n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int main()
{
    int arr[] = {30, 40, 10, 80, 5, 12, 70, 343, 233};

    bucket_sort(arr, 9, 4);

    cout << "\nArray elements : ";
    for(int i=0; i<9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}