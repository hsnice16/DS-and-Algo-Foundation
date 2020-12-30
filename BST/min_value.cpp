// program to find minimum value in Binary Search Tree

#include <iostream>
#include <stdexcept>
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

// function returning minimum value in BST
int min_val(Node *root)
{
    if (root == NULL)
        throw runtime_error("Tree is empty !!");

    while (root->left)
        root = root->left;

    return (root->key);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->left = new Node(0);
    root->left->left->right = new Node(1);
    root->left->left->left = new Node(-1);
    root->right = new Node(5);

    try
    {
        int val = min_val(root);
        cout << "\nMinimum value in tree is : " << val;
    }
    catch (exception &err)
    {
        cout << err.what() << endl;
    }
    return 0;
}