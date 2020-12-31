/*
    The diameter of a tree (sometimes called the width) is the number
    of nodes on the longest path between two end nodes. 

    The diameter of a tree T is the largest of the following quantities:
    1.) The diameter of T's left subtree
    2.) The diameter of T's right subtree
    3.) The longest path between leaves that goes through the root
        of T(this can be computed from the heights of the subtrees of T).
        longest path = 1 + height of left subtree of nd + height of right subtree of nd
*/

#include <algorithm>
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

// calculate height of the tree
int height(Node *root)
{
    // base case
    if (root == NULL)
        return 0; // return 0;

    // height of the tree is maximum height of the left
    // subtree or right subtree + 1(for root)
    return (1 + max(height(root->left), height(root->right)));
}

// calculate diameter of the tree
/*
    time complexity : O(N^2), where N is the number of nodes in the
                            binary tree.
*/
int diameter(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // calculating height of left sub-tree and right sub-tree
    int left_height = height(root->left);
    int right_height = height(root->right);

    // calculating diameter of left subtree and right subtree
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(max(left_diameter, right_diameter), (1 + left_height + right_height));
}

int main()
{
    /*
                                1
                               /  \
                              2    3
                             / \
                            4   5
                          /   \   \
                          6   7    8
                              /   / \
                              9   10 11
                              \      /
                              12     13
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->right->right = new Node(8);
    root->left->left->right->left = new Node(9);
    root->left->right->right->left = new Node(10);
    root->left->right->right->right = new Node(11);
    root->left->left->right->left->right = new Node(12);
    root->left->right->right->right->left = new Node(13);

    cout << "\nDiameter of the given tree : " << diameter(root);

    return 0;
}