// Iterative PostOrder traversal implementation

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

// postorder traversal
void postOrder(Node *root)
{
    stack<Node *> stk;
    Node *p = root, *q = root;
    while (p)
    {
        while (p->left)
        {
            stk.push(p);
            p = p->left;
        }
        while (p->right == NULL || p->right == q)
        {
            cout << p->key << ' ';
            q = p;
            if (stk.empty())
                return;
            p = stk.top();
            stk.pop();
        }
        stk.push(p);
        p = p->right;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    postOrder(root);

    return 0;
}