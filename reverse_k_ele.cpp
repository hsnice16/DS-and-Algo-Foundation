/**
    Reversing the first K elements of a queue
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse_k(queue<int> &q, int k)
{
    if (q.empty() == true || k <= 0 || k > q.size())
        return;

    stack<int> s;
    int n = q.size();

    // push first k elements in stack;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // pop from stack and push in queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // pop remaining elements of queue(before pushing from stack) and push back in queue
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    int num;
    cout << "\nenter number of elements in queue : ";
    cin >> num;

    queue<int> q;

    for (int i = 0; i < num; i++)
    {
        int temp;
        cout << "\nenter value " << i + 1 << " of queue : ";
        cin >> temp;

        q.push(temp);
    }

    int k;
    cout << "\nenter number of element to reverse : ";
    cin >> k;

    reverse_k(q, k);

    cout << "\nAfter reverse method : ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}