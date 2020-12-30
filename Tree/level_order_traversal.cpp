// Program traversing Tree Level by Level(Breadth first search)
// from left to right

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

// function for BFS
/*
    Time Complexity: theta(n)
    Auxiliary Space: O(n) or more accurate theta(w) , where w is width of binary tree
*/
void BFS_traversal(Node *root)
{
    if (root != NULL)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

int main()
{
    Node *head = new Node(10);
    head->left = new Node(15);
    head->left->left = new Node(30);
    head->right = new Node(20);
    head->right->left = new Node(40);
    head->right->right = new Node(50);
    head->right->left->left = new Node(60);
    head->right->left->right = new Node(70);

    BFS_traversal(head);

    return 0;
}