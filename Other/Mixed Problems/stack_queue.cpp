/** 
implementation of queue using stacks

** we will use two stacks to implement queue data structure
** There can be two method to implement queue data structure using two stacks
** Method 1, making enqueue operation costly
** Method 2, making dequeue operation costly

*/

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enqueue(int data)
    {
        /*
        // Method 1

        // pushing all data from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // pushing new data in s1
        s1.push(data);

        // pushing all data back in s1 from s2
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        */
            // Method 2

            s1.push(data);
        
    }

    int dequeue()
    {
        /*
        // Method 1

        if (s1.empty())
        {
            cout << "\nqueue is empty !!!";
            exit(0);
        }

        int data = s1.top();
        s1.pop();
        return data;

        */
            // Method 2

            if (s1.empty() && s2.empty())
            {
                cout << "\nqueue is empty !!!";
                exit(0);
            }

            if (s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            int data = s2.top();
            s2.pop();
            return data ;
        
    }
};

int main()
{

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "\n1 : " << q.dequeue();
    cout << "\n2 : " << q.dequeue();
    cout << "\n3 : " << q.dequeue();

    return 0;
}