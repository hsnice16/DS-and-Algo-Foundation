// implementation of Inorder traversal of Single Threaded Binary Tree

/*
    Threaded Binary Trees can be:
    1. Single Threaded:
        Where a NULL right pointers is made to point to the inorder successor (if successor exists).
    2. Double Threaded:
        Where both left and right NULL pointers are made to point to inorder predecessor and inorder
        successor respectively.
        The predecessor threads are useful for reverse inorder traversal and postorder traversal.
*/

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    bool rightThread;
    Node(int key)
    {
        this->left = this->right = NULL;
        this->key = key;
        this->rightThread = false;
    }
};

class ThreadedBinary
{
    Node *root;

public:
    ThreadedBinary() : root(NULL) {} // constructor
    void insert(const int &el);      // insert new node
    void inorder();                  // inorder traversal
    Node *leftmost(Node *n);         // left most node
};

void ThreadedBinary::insert(const int &el)
{
    Node *curr = this->root;
    Node *prev = NULL;
    Node *successor = NULL;
    Node *newNode = new Node(el);

    // search where to insert
    while (curr)
    {
        prev = curr;
        if (curr->key < el)
        {
            if (curr->rightThread) // if current node has rightThread == true
            {
                curr->right = NULL;
                curr->rightThread = false;
            }
            curr = curr->right; // go right subtree
        }
        else
        {
            successor = curr;  // successor only contain value if new node
                               // goes in left subtree of curr node
            curr = curr->left; // go left subtree
        }
    }

    if (this->root == NULL)
        this->root = newNode;
    else if (prev->key < el)
        prev->right = newNode; // right child
    else
        prev->left = newNode; // left child

    // adding thread
    if (successor) // if successor is not NULL
    {
        newNode->right = successor;
        newNode->rightThread = true;
    }
}

Node *ThreadedBinary::leftmost(Node *n)
{
    if (n == NULL)
        return n;

    while (n->left)
        n = n->left;

    return n;
}

void ThreadedBinary::inorder()
{
    Node *curr = leftmost(root); // get left most node of root

    while (curr)
    {
        cout << curr->key << ' ';

        // if rightThread is true exist
        if (curr->rightThread)
        {
            curr = curr->right;
        }
        else
        {
            curr = leftmost(curr->right);
        }
    }
}

int main()
{
    /*
                                                    5
                                           /                 \
                                           2                 7
                                /                  \       /     \
                                1->2(threaded)    4->5   6->7     9
                                                  /            /     \
                                                3->4         8->9     10
    */

    ThreadedBinary obj;

    obj.insert(5);
    obj.insert(2);
    obj.insert(7);
    obj.insert(1);
    obj.insert(4);
    obj.insert(6);
    obj.insert(9);
    obj.insert(8);
    obj.insert(10);
    obj.insert(3);

    cout << "\nInorder Traversal : ";
    obj.inorder();

    return 0;
}
