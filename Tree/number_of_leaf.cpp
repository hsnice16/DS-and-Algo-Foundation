// program to find number of leaves in the tree

#include <iostream>
#include <queue>
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

// count number of leaf
int count_leaf(Node *root)
{
    if (root == NULL) // if tree is empty
        return 0;

    int count = 0; // counter variable, to count leaves
    queue<Node *> q;
    q.push(root);

    // loop until queue doesn't become empty
    while (!q.empty())
    {
        bool check = true;
        if (q.front()->left) // if left child exist
        {
            check = false;
            q.push(q.front()->left);
        }

        if (q.front()->right) // if right child exist
        {
            check = false;
            q.push(q.front()->right);
        }

        // if check remains true , it means
        // front node present in queue , neither has
        // left child or right child , means a leaf
        if (check)
            count++;

        // pop front element of queue
        q.pop();
    }

    return count; // count of leaf
}

/*
int count_leaf(Node *root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}
*/

int main()
{
    /*
                 1
               /   \
              2     3
                   /  \
                  4    5
                        \
                         6
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);

    cout << "\nNumber of leaves in the tree : " << count_leaf(root);

    return 0;
}