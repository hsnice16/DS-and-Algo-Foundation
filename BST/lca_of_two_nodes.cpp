/*
    Problem: Given values of two nodes n1 and n2 in a Binary Search
    Tree, find the Lowest Common Ancestor (LCA). For simplicity, you may assume
    that both the values exist in the tree.

    Since Binary Search Tree is also a Binary Tree, we can apply the same process of
    finding LCA of two nodes in BST as that of binary trees. But finding LCA in a Binary
    Tree takes O(N) time complexity. This can be improved in BST.
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
        this->key = key;
        this->left = this->right = NULL;
    }
};

/*
// recursive implementation
Node *lca(Node *root, int n1, int n2)
{
    if(root == NULL)
        return root;

    // If both n1 and n2 are smaller than root,
    // then LCA lies in left subtree
    if(root->key > n1 && root->key > n2)
        return lca(root->left, n1, n2);

    // If both n1 and n2 are greater than root,
    // then LCA lies in right subtree
    if(root->key < n1 && root->key < n2)
        return lca(root->right, n1, n2);

    // else return root
    return root;
}
*/

// iterative implementation
/*
    Time complexity : O(height)
    Auxiliary Space : O(1)
*/
Node *lca(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->key > n1 && root->key > n2)
            root = root->left;
        else if (root->key < n1 && root->key < n2)
            root = root->right;
        else
            break;
    }
    return root;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);

    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    cout << "LCA of " << n1 << " and " << n2 << " is : " << lca(root, n1, n2)->key;

    n1 = 14, n2 = 8;
    cout << "\nLCA of " << n1 << " and " << n2 << " is : " << lca(root, n1, n2)->key;

    n1 = 10, n2 = 22;
    cout << "\nLCA of " << n1 << " and " << n2 << " is : " << lca(root, n1, n2)->key;

    return 0;
}