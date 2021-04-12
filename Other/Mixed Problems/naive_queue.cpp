// naive approach of queue data structure, using array

#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int capacity;
    int *arr;

public:
    Queue(int cap);
    ~Queue();
    void enqueue(int data);
    void dequeue();
    bool empty();
    int getFront();
    int getRear();
};
Queue::Queue(int cap)
{
    capacity = cap;
    size = 0;
    arr = new int[cap];
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue::enqueue(int data)
{
    if (size == capacity)
        throw runtime_error("Queue is Full!");

    arr[size] = data;
    size++;
}

void Queue::dequeue()
{
    if (empty())
        throw runtime_error("Queue is empty!");

    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

bool Queue::empty()
{
    return size == 0;
}

int Queue::getFront()
{
    if (empty())
        throw runtime_error("Queue is empty!");

    return arr[0];
}

int Queue::getRear()
{
    if (empty())
        throw runtime_error("Queue is empty!");

    return arr[size - 1];
}

int main()
{

    int cap;
    cout << "enter capacity of Queue : ";
    cin >> cap;

    Queue qu(cap);
    int choice;

    do
    {
        cout << "\nMenu:\n"
             << "1. enqueue\n"
             << "2. dequeue\n"
             << "3. empty\n"
             << "4. get front\n"
             << "5. get rear\n"
             << "6. quit\n";
        cout << "\nenter your choice(1-5)";
        cin >> choice;

        switch (choice)
        {
        case 1:
            try
            {
                int data;
                cout << "\nenter data to add : ";
                cin >> data;
                qu.enqueue(data);
                cout << "\ndata added successfully!";
            }
            catch (const std::exception &e)
            {
                cerr << e.what() << '\n';
            }

            break;

        case 2:
            try
            {
                qu.dequeue();
                cout << "\nfront data is removed.";
            }
            catch (const exception &err)
            {
                cout << endl
                     << err.what();
            }
            break;

        case 3:
            if (qu.empty())
                cout << "\nQueue is empty!";
            else
                cout << "\nQueue is not empty!";
            break;

        case 4:
            try
            {
                int data = qu.getFront();
                cout << "\nFront data of queue is : " << data;
            }
            catch (const exception &err)
            {
                cout << endl
                     << err.what();
            }
            break;

        case 5:
            try
            {
                int data = qu.getRear();
                cout << "\nRear data of queue is : " << data;
            }
            catch (const exception &err)
            {
                cout << endl
                     << err.what();
            }
            break;

        case 6:
            break;

        default:
            cout << "\nChoose Right Option!!\n";
            break;
        }
    } while (choice != 6);

    return 0;
}