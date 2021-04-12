/**
    array implementation of deque data structure
*/

#include <iostream>
using namespace std ;

struct Deque
{
    int *arr ;
    int front , size, cap;
    Deque(int c) ;
    void insert_front(int data);
    void insert_rear(int data);
    int get_rear();
    int get_front();
    void delete_front();
    void delete_rear();
    bool isempty();
    bool isFull();
    int ele_num();      // get number of elements
};

Deque::Deque(int c)
{
    cap = c;
    size = 0;
    front = 0;
    arr = new int[cap];
}

bool Deque::isempty()
{
    return (size == 0);
}

bool Deque::isFull()
{
    return (size == cap);
}

int Deque::ele_num()
{
    return size ;
}

void Deque::insert_front(int data)
{
    if (isFull())
        return ;

    front = (front - 1 + cap)%cap;
    arr[front] = data ;
    size++ ;
}

void Deque::insert_rear(int data)
{
    if (isFull())
        return ;

    int new_rear = (front + size)%cap;
    arr[new_rear] = data ;
    size++ ;
}

int Deque::get_front()
{
    if (isempty())
        return -1;

    return arr[front];
}

int Deque::get_rear()
{
    if (isempty())
        return -1 ;

    int rear = (front + size - 1)%cap ;
    return arr[rear] ;
}

void Deque::delete_front()
{
    if(isempty())
        return ;

    front = (front + 1)%cap;
    size--;
}

void Deque::delete_rear()
{
    if(isempty())
        return ;
    size-- ;
}

int main()
{

    Deque d(3);

    d.insert_front(1);
    d.insert_rear(3);
    d.insert_front(2);

    cout << "size : " << d.ele_num() << endl ;
    cout << "front : " << d.get_front() << endl ;
    d.delete_front();
    cout << "front : " << d.get_front() << endl;
    cout << "rear : " << d.get_rear() << endl ;
    d.delete_rear();
    cout << "front : " << d.get_front() << endl ;
    cout << "rear : " << d.get_rear() << endl ;
    d.delete_front() ;
    cout << "front : " << d.get_front() << endl ;
    cout << "rear : " << d.get_rear() << endl ;
    cout << "size : " << d.ele_num() << endl ;

    return 0;
}