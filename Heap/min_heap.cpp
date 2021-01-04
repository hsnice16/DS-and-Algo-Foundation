// Implementation of min heap data structure

#include <iostream>
#include <limits>
#include <utility>
using namespace std;

// MinHeap class
class MinHeap
{
    int *arr; // dynamic array
    int size;
    int capacity;

public:
    MinHeap(int cap);                   // constructor
    ~MinHeap();                         // destructor
    int left(int ind);                  // get index of left child
    int right(int ind);                 // get index of right child
    int parent(int ind);                // get index of parent
    int getMin();                       // get minimum
    void insert(int val);               // insert operation
    void buildHeap();                   // build heap function
    void decreaseKey(int ind, int val); // insert value 'val' at index 'ind'
    void deleteKey(int ind);            // delete element at index 'ind'
    void minHeapify(int ind);           // heapify operation
    void extractMin();                  // extract minimum
    void display();                     // display
};

MinHeap::MinHeap(int cap)
{
    this->capacity = cap;
    this->size = 0;
    this->arr = new int(cap);
}

MinHeap::~MinHeap()
{
    delete[] arr;
}

inline int MinHeap::left(int ind)
{
    return (2 * ind + 1);
}

inline int MinHeap::right(int ind)
{
    return (2 * ind + 2);
}

inline int MinHeap::parent(int ind)
{
    return ((ind - 1) / 2);
}

inline int MinHeap::getMin()
{
    return arr[0];
}

/*
    time complexity : O(log|size|)
*/
void MinHeap::insert(int val)
{
    if (size == capacity)
        return;

    size++;
    arr[size - 1] = val;

    int i = size - 1;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int ind, int val)
{
    arr[ind] = val;
    int i = ind;
    while (i != 0 && (arr[parent(i)] > arr[i]))
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int ind)
{
    decreaseKey(ind, numeric_limits<int>::min());
    extractMin();
}

/*
    Min Heapify :  given a Binary Heap with one 
                   possible violation, fix the Heap

    Time complexity : O(log|size|)
    Auxiliary space : O(log|size|) (Recursive function)
*/
void MinHeap::minHeapify(int ind)
{
    // first find smallest index of three value
    // (root with given index, its left child, its right child)
    int lt = left(ind), rt = right(ind);
    int smallest = ind;

    if (lt < size && arr[lt] < arr[ind])
        smallest = lt;
    if (rt < size && arr[rt] < arr[smallest])
        smallest = rt;

    // if smallest value index is not equal to given index
    if (smallest != ind)
    {
        swap(arr[smallest], arr[ind]);
        minHeapify(smallest);
    }
}

void MinHeap::extractMin()
{
    if (size == 1)
    {
        size--;
        return;
    }
    swap(arr[0], arr[size - 1]);
    size--;
    minHeapify(0);
}

/*
    Build Heap  :   Given a random array, rearrange its elements to form a min heap
    Time Complexity : O(size) (explaination in intro file)
*/
void MinHeap::buildHeap()
{
    for (int i = (size - 2) / 2; i >= 0; i--)
        minHeapify(i);
}

void MinHeap::display()
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}

int main()
{
    MinHeap obj(10);
    obj.insert(10);
    obj.insert(100);
    obj.insert(70);
    obj.insert(80);
    obj.insert(20);
    obj.insert(40);

    cout << "\nMinHeap contains : ";
    obj.display();

    cout << "\nBefore extract min, Top : ";
    cout << obj.getMin();

    obj.extractMin();

    cout << "\nAfter extract min, Top : ";
    cout << obj.getMin();

    cout << "\nMinHeap contains : ";
    obj.display();
    return 0;
}