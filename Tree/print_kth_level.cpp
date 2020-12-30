// program printing node at kth level, if level starts from 0

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int key) // constructor
    {
        this->key = key;
        left = right = NULL;
    }
};

// function printing node at kth level
/*
    Time Complexity: O(n)
    Auxiliary Space : O(n)
*/
void at_kth(Node *root, int k)
{
    if (root == NULL)
        return;
    else if (k == 0)
        cout << root->key << " ";
    at_kth(root->left, k - 1);
    at_kth(root->right, k - 1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);

    int k = 3; // at kth level
    at_kth(root, k);

    return 0;
}