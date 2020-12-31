// program to convert Binary Tree into its Mirror Tree

/* 
    Basic Idea : Interchange left and right children of all non-leaf nodes.

            1                                     1
           / \         Mirror Image              / \
           3  2          ---->                  2  3
             / \                               / \
             5  4                              4  5
*/

#include <iostream>
using namespace std;

struct Node // Node of Tree
{
    int key;
    Node *left, *right;
    Node(int key)
    {
        this->left = this->right = NULL;
        this->key = key;
    }
};

// converting into mirror image
void mirror(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        /* swap children */
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;

        /* call for children */
        mirror(root->left);
        mirror(root->right);
    }
}

// inorder traversal
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << ' ';
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << "Original Tree : ";
    inorder(root);

    mirror(root);
    cout << "\nMirror Image of Tree : ";
    inorder(root);

    return 0;
}