// Iterative inorder traversal

#include <iostream>
#include <stack>
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

// Iterative inorder
void inorder(Node *root)
{
    stack<Node *> stk;
    while (root || !stk.empty())
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        cout << root->key << ' ';
        stk.pop();
        root = root->right;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    inorder(root);

    return 0;
}