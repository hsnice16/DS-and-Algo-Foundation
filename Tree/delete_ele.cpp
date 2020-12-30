// program to delete given element from the tree,
// assuming element is present in the tree

#include <iostream>
#include <queue>
using namespace std;

// Node of the tree
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

// inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << ' ';
        inorder(root->right);
    }
}

/*
// Function to delete the given deepest node last_node in 
// binary tree

void deleteDeepest(Node *root, Node *last_node)
{
    queue<Node *> q;
    q.push(root);

    // Do level order traversal until last node
    Node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->right)
        {
            if(temp->right == last_node)
            {
                temp->right = NULL;
                delete(last_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if(temp->left)
        {
            if(temp->left == last_node)
            {
                temp->left = NULL;
                delete(d_node);
                return ;
            }
            else
                q.push(temp->left);
        }
    }
}
*/

// deletion
void deletion(Node *root, int key)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    Node *to_delete;
    Node *last_node;

    while (!q.empty())
    {
        last_node = q.front();
        q.pop();
        if (last_node->key == key)
            to_delete = last_node;
        if (last_node->left)
            q.push(last_node->left);
        if (last_node->right)
            q.push(last_node->right);
    }

    /*
        int x = last_node->key;
        deleteDeepest(root, last_node);
        to_delete->key = x;
    */
    to_delete->key = last_node->key;
    Node *temp = last_node;
    last_node = NULL;
    delete (temp);

    return;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "\nBefore deletion : ";
    inorder(root);

    int key = 11;
    deletion(root, key);

    cout << "\nAfter deletion , node with key 11 : ";
    inorder(root);

    return 0;
}