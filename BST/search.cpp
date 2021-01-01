// implementation of search operation in Binary Search Tree

#include <iostream>
using namespace std;

// Node
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

// recursive implementation
/*
    Auxiliary space : O(height)
    Time complexity : O(height)
*/

bool search(Node *root, int k)
{
    if (root == NULL)
        return false;
    else if (root->key == k)
    {
        return true;
    }
    else if (root->key > k)
    {
        return search(root->left, k);
    }
    else
    {
        return search(root->right, k);
    }
}

// iterative implementation
/*
    Auxiliary Space : O(1)
    Time complexity : O(height)
*/
/*
bool search(Node *root, int k)
{
    while (root != NULL)
    {
        if (root->key == k)
            return true;
        else if (root->key > k)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}
*/

int main()
{
    Node *root = new Node(15);

    root->left = new Node(5);
    root->left->left = new Node(3);

    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);
    root->right->left->left = new Node(16);

    cout << "19 is present ? " << std::boolalpha << search(root, 19);

    return 0;
};