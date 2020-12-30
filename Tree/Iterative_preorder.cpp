// Iterative preorder

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

// function doing pre-order
void preOrder(Node *root)
{
    if (root == NULL)
        return;

    /*      first method

    // Auxiliary Space: O(n)

    stack<Node *> stk;
    stk.push(root);
    Node *curr = root;
    while (!stk.empty())
    {
        Node *curr = stk.top();
        stk.pop();
        cout << curr->key << ' ';
        if (curr->right)
            stk.push(curr->right);
        if (curr->left)
            stk.push(curr->left);
    }
*/
    /*  second method 

        Auxiliary Space : O(height of the tree)
    */
    stack<Node *> stk;
    Node *curr = root;

    while (curr || !stk.empty())
    {
        while (curr)
        {
            cout << curr->key << ' ';
            if (curr->right)
                stk.push(curr->right);
            curr = curr->left;
        }
        if (!stk.empty())
        {
            curr = stk.top();
            stk.pop();
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    preOrder(root);

    return 0;
}