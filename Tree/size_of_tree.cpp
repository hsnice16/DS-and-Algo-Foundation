// Program to find size of given binary tree

#include <iostream>
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

// function counting number of nodes in given tree
int size(Node *root)
{
    /*
        Recursive
            Time Complexity: O(n)
            Auxiliary Space: O(height of the tree)
    */
    if (root == NULL)
        return 0;

    return 1 + size(root->left) + size(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);

    cout << "\nNumber of nodes in Tree : " << size(root);

    return 0;
}