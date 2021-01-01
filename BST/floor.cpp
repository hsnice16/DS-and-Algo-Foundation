// Implementation of Program which returns floor of a value in BST

#include <iostream>
using namespace std;

// tree node
struct Node
{
    int key;
    Node *left, *right;
    Node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
};

// function returning floor of a value(if it exists)
int floor(Node *root, int k)
{
    int val = -1;
    while (root != NULL)
    {
        if (root->key == k)
            return k;
        else if (root->key > k)
            root = root->left;
        else
        {
            val = root->key;
            root = root->right;
        }
    }
    return val;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    root->right->left->left = new Node(55);
    root->right->left->right = new Node(65);

    cout << "\nFloor value of 25 : " << floor(root, 25);

    return 0;
}