// program finding frequency of array elements

#include <iostream>
#include <unordered_map>
using namespace std;

void countFreq(int arr[], int size)
{
    unordered_map<int, int> um;

    for (int i = 0; i < size; i++)
    {
        /*
        if(um.find(arr[i]) == um.end())
            um[arr[i]] = 1;
        else
            um[arr[i]] += 1;
        */
        um[arr[i]]++;
    }

    cout << "\nFrequency : \n";
    for (auto val : um)
        cout << val.first << " " << val.second << endl;
}

int main()
{

    int size;
    cout << "\nenter size of array : ";
    cin >> size;

    int arr[size];
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "). ";
        cin >> arr[i];
    }

    countFreq(arr, size);

    return 0;
}