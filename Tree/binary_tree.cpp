// Basic Implementation of Binary Tree

#include <algorithm>
#include <iostream>
using namespace std;

// node of Binary Tree
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

// Implementation of inorder traversal
/*
    Time Complexity : O(n), doing constant amount of work for every node
    Auxiliary Space : O(height of tree), at most height of the tree, function call will be in stack occur
*/
void inorder(Node *root)
{
    if (root != NULL) // if root is not NULL, only then process
    {
        inorder(root->left);      // process left subtree
        cout << root->key << " "; // process root
        inorder(root->right);     // process for right subtree
    }
}

// Implementation of preorder traversal
/*
    Time Complexity and Auxiliary Space are same as inorder traversal
*/
void preorder(Node *root)
{
    if (root != NULL) // if tree is not empty
    {
        cout << root->key << " "; // process root
        preorder(root->left);     // process left subtree
        preorder(root->right);    // process right subtree
    }
}

// Implementation of postorder traversal
/*
    Time Complexity and Auxiliary Space are same as inorder traversal
*/
void postorder(Node *root)
{
    if (root != NULL) // if tree is not empty
    {
        postorder(root->left);    // process left subtree
        postorder(root->right);   // process right subtree
        cout << root->key << " "; // process root
    }
}

// function calculating height of the tree
/*
    Time Complexity : O(n), we are doing constant amount of work for every node
    Auxiliary Space : O(height of tree)
*/
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left_height = height(root->left);      // height of left subtree
    int right_height = height(root->right);    // height of rigth subtree
    return max(left_height, right_height) + 1; // height of the tree

    /*
        Alternatively,
            if (root == NULL)
                return 0;
            return max(height(root->left), height(root->right)) + 1;
    */
}

int main()
{
    /*
        Node *root = NULL;  // empty tree
    */

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << "\nTree Data : ";
    cout << "\nUsing Inorder Traversal : ";
    inorder(root);
    cout << "\nUsing Preorder Traversal : ";
    preorder(root);
    cout << "\nUsing Postorder Traversal : ";
    postorder(root);

    cout << "\n\nHeight of the Tree : " << height(root);
    return 0;
}