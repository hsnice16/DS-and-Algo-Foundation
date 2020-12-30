// program finding total number of nodes
// and total number of nodes in left child

#include <iostream>
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

// function counting total number of nodes in the tree
int count_nodes(Node *root)
{
    if (root == NULL) // base case
        return 0;
    else
    {
        return (1 + count_nodes(root->left) + count_nodes(root->right));
    }
}

// function counting total number of nodes in left child
int count_left_nodes(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return count_nodes(root->left);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "\nTotal number of nodes in the tree : " << count_nodes(root);
    cout << "\nTotal number of nodes in the left subtree : " << count_left_nodes(root);

    return 0;
}