// program to find ceil of a value, using BST

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

// function returning ceil
int ceil(Node *root, int k)
{
    int val = -1;
    while (root != NULL)
    {
        if (root->key == k)
            return k;
        else if (root->key < k)
            root = root->right;
        else
        {
            val = root->key;
            root = root->left;
        }
    }
    return val;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->right->left = new Node(12);
    root->right->right = new Node(30);

    int ceil_find;
    cout << "\nEnter value of which ceil to find : ";
    cin >> ceil_find;
    cout << "\nCeil of " << ceil_find << " : " << ceil(root, ceil_find);

    return 0;
}