/*
    Problem : Given a Binary Tree and the value of two nodes n1 and n2. 
    The task is to find the lowest common ancestor of the nodes n1 and n2 in the given Binary Tree.

    The LCA or Lowest Common Ancestor of any two nodes n1 and n2 is 
    defined as the common ancestor of both the nodes which is closest to them.
    That is the distance of the common ancestor from the nodes n1 and n2 should be least possible.
*/

#include <iostream>
#include <vector>
using namespace std;

// tree node
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

/*
// First Approach
bool findPath(Node *root, vector<int> &path, int n)
{
    // base case
    if (root == NULL)
        return false;

    // push the root key in vector as the starting point of the tree
    // if this tree does not contain 'n' then , it will be removed from path
    path.push_back(root->key);

    if (root->key == n) // checking if n is same as root key
        return true;

    // now searching , if k is present in left or right subtree
    if (findPath(root->left, path, n) || findPath(root->right, path, n))
        return true;

    // if not present in the subtree rooted with root,
    // remove root from path and return false
    path.pop_back();

    return false;
}

int findLCA(Node *root, int n1, int n2)
{
    // to store paths of n1 and n2 from root
    vector<int> path1, path2;

    // check if both the nodes present or not
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1; // one of the node is not present in the tree

    int i;
    // loop from both the path untill a different node exist
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;

    return path1[i - 1]; // LCA
}

// time complexity : O(n), n is number of nodes
// auxiliary space : O(n)
// required two tree traversal and extra space
*/

// Second Approach
/*
    Assumption : the keys are present in the Binary Tree.
*/

Node *findLCA(Node *root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches with root's key , report
    // the presence by returning root ( Note that if a key is ancestor
    // of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL,
    // then one key is present in once subtree and
    // other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)
        return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "\nLCA(4, 5) = " << findLCA(root, 4, 5)->key; // 4 and 5 are keys
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;

    return 0;
}