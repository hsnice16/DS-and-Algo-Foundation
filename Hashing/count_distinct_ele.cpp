// program to find , number of distinct element in array

#include <iostream>
#include <unordered_set>
using namespace std;

int countDistinct(int arr[], int size)
{
    unordered_set<int> s;

    for(int i=0; i<size; i++)
    {
        s.insert(arr[i]);
    }

    return s.size();
}

int main()
{

    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for(int i=0; i<size; i++)
    {
        cout << i+1 << "). ";
        cin >> arr[i];
    }

    cout << "\nNumber of distinct element : " << countDistinct(arr, size);

    return 0;
}