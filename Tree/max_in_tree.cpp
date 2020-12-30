// Program to find maximum value in a tree

#include <algorithm>
#include <iostream>
#include <limits>
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

// function finding maximum value in tree
/*
    Time Complexity : O(n)
    Auxiliary Space : O(height of tree)
*/
int getMax(Node *root)
{
    if (root == NULL)
        return numeric_limits<int>::min();      // -ive infinite
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << "\nMaximum value in tree : " << getMax(root);

    return 0;
}