/*
    Problem : Median of Stream of Running Integers using STL

    Description - Given that integers are being read from a data stream.
                    Find median of all the elements read so far starting from the first 
                    integer till the last integer. This is also called Median of Running
                    Integers. The data stream can be any source of data, example: a file,
                    an array of integers, input stream etc.

    What is Median ?    an element in the data set which separates the higher half of the 
                        data sample from the lower half.
                        for odd number of elements : middle element is median
                        for even number of elements : average of middle elements
    Example:    Input:5 10 15
                Output:5
                       7.5
                       10
*/
#include <iostream>
#include <queue>
using namespace std;
#define neg (-1)* 


// print function
void print(double val)
{
    cout << val << endl;
}

// function printing median
void printMedian(double arr[], int size)
{
    priority_queue<double> max_h; // to store lower half
    priority_queue<double> min_h; // to store higher half

    cout << "\nOutput : \n";

    double median = arr[0];
    max_h.push(median);
    print(median);

    // reading stream
    for (int i = 1; i < size; i++)
    {
        double temp = arr[i];

        // case #1: elements in lower half > elements in higher half
        if (max_h.size() > min_h.size())
        {
            if (temp < median)
            {
                min_h.push(neg max_h.top());   // to make min heap
                max_h.pop();
                max_h.push(temp);
            }
            else
            {
                min_h.push(neg temp);
            }
            median = (neg min_h.top() + max_h.top()) / 2;
        }
        // case #2: elements in lower half < elements in higher half
        else if (max_h.size() < min_h.size())
        {
            if (temp > median)
            {
                max_h.push(neg min_h.top());
                min_h.pop();
                min_h.push(neg temp);
            }
            else
            {
                max_h.push(temp);
            }
            median = (neg min_h.top() + max_h.top()) / 2;
        }
        // case #3: elements in lower half == elements in higher half
        else
        {
            if ( temp < median)
            {
                max_h.push(temp);
                median = max_h.top();
            }
            else
            {
                min_h.push(neg temp);
                median = neg min_h.top();
            }
        }
        print(median);
    }
}

int main()
{
    int size;
    cout << "\nHow many numbers are there in stream ?(enter) ";
    cin >> size;

    double arr[size];
    cout << "\nStart entering your numbers : \n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ") ";
        cin >> arr[i];
    }

    printMedian(arr, size);
    return 0;
}