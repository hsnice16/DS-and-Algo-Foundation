/**
Implementaiton of stack using queue

** we are going to use two queue to implement stack using queue
** There are two methods to implement this
** Method 1, making push operation costly
** Method 2, Making pop operation costly

*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;

    // to maintain current size
    int c_size;

public:
    Stack();
    void push(int data);
    void pop();
    int top();
    int Size();
};

Stack::Stack()
{
    c_size = 0;
}

void Stack::push(int data)
{
    c_size++;

    /*  // Method 1
    q2.push(data);

    // pushing all the data from q1 to q2
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    queue<int> q = q1;
    q1 = q2;
    q2 = q;
*/
    q1.push(data);
}

void Stack::pop()
{
    if (q1.empty())
    {
        cout << "\nStack is empty()";
        exit(0);
    }
    /*  // Method 1
    q1.pop();
*/
    c_size--;

    // method 2
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    q1.pop();

    queue<int> q = q1;
    q1 = q2;
    q2 = q1;
}

int Stack::top()
{
    if (q1.empty())
        return -1;

    // method 1
    // return q1.front();

    // method 2

    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    // last pushed element
    int temp = q1.front();

    // to empty the auxiliary queue after
    // last operation
    q1.pop();

    // push last element to q2
    q2.push(temp);

    // swap the two queues names
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
    return temp;
}

int Stack::Size()
{
    return c_size;
}

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "\nCurrent size : " << s.Size();
    cout << "\ntop : " << s.top();
    s.pop();
    cout << "\ntop : " << s.top();
    s.pop();
    cout << "\ntop : " << s.top();
    s.pop();
    cout << "\nCurrent size : " << s.Size();

    return 0;
}