// Implementation of delete operation in Binary Search Tree

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

// smallest greater value
Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;

    return curr;
}

// recursive implementation
/*
    Auxiliary space and time complexity requirements are
    same as search operation
*/

Node *delNode(Node *root, int k)
{
    if (root == NULL)
        return root;
    else if (root->key > k)
        root->left = delNode(root->left, k);
    else if (root->key < k)
        root->right = delNode(root->right, k);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delNode(root->right, succ->key);
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(10);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    root = delNode(root, 50);
    cout << root->key << ' ';

    return 0;
}