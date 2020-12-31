// Program to convert binary tree into Doubly Linked List.

/*
    The conversion is in-place (same as inorder traversal of BT)
*/

#include <iostream>
using namespace std;

// tree node
struct Node
{
    int key;
    Node *left, *right;
    Node(int key)
    {
        this->left = this->right = NULL;
        this->key = key;
    }
};

// function converting Binary Tree into Doubly Linked List
void BT_2_DLL(Node *root, Node **head)
{
    if (root == NULL)
        return;

    // Initialize previously visited node as NULL. This is static
    // so that the same value is accessible in all recursive calls
    static Node* prev = NULL;

    // Recursively convert left subtree
    BT_2_DLL(root->left, head);

    // Now conver this node
    if( prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    
    // Finally convert right subtree
    BT_2_DLL(root->right, head);
}

// function displaying Doubly Linked List
void display_DLL(Node **head)
{
    Node *curr = *head;
    while(curr)  // curr != NULL
    {
        cout << curr->key << ' ';
        curr = curr->right;
    }
}

int main()
{
    /*
              10
            /   \
           12   15
          / \   /
         25 30  36
    */

    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node **head ;
    BT_2_DLL(root, head);

    cout << "\nDisplay List : ";
    display_DLL(head);

    return 0;
}