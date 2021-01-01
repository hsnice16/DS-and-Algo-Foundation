// Implementation of insertion operation in Binary Search Tree

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

/*
    Time complexity and Auxiliary space requirements of
    recursive and iterative implementation are same as
    search operation
*/

/*
// recursive implementation
Node *insert(Node *root, int k)
{
    if (root == NULL)
        return new Node(k);
    else if (root->key > k)
        root->left = insert(root->left, k);
    else if (root->key < k)
        root->right = insert(root->right, k);
    return root;
}
*/

// iterative implementation
Node *insert(Node *root, int k)
{
    if (root == NULL)
        return new Node(k);
    else
    {
        Node *curr = root;
        Node *prev = NULL;

        while (curr) // curr != NULL
        {
            prev = curr;
            if (curr->key == k)
                return root;
            else if (curr->key > k)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (prev->key > k)
            prev->left = new Node(k);
        else
            prev->right = new Node(k);
        return root;
    }
}


int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    cout << root->key;

    cout << endl;
    root = insert(root, 5);
    cout << root->key << ' ';
    cout << root->left->key << ' ';
    return 0;
}