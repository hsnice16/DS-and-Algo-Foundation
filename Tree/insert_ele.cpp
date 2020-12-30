/*
    Problem : Given a Binary Tree and a Key. The task is to insert
    the key into the binary tree at first position available in level order.    
*/

#include <iostream>
#include <queue>
using namespace std;

// node of the tree
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

// inorder traversal of tree
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << ' ';
        inorder(root->right);
    }
}

// level by level traversal
void insert(Node *root, int key)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = new Node(key);
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = new Node(key);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->right = new Node(8);

    cout << "\nInorder traversal before insertion : ";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout << "\nInorder traversal after insertion : ";
    inorder(root);

    return 0;
}