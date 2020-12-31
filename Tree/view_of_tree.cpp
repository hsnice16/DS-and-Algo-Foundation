/*
    Problem : Given a Binary Tree. The task is to print the nodes of the
    binary tree when viewed from different sides. That is , the left view of
    the binary tree will contain only those nodes which can be seen when
    the Binary tree is viewed from left.

    example :
        Consider the Below Binary Tree:
                                    1
                                  /   \
                                 2     3
                                / \   / \
                                4  5  6  7

        Left View of above Tree will be: 1, 2, 4
        Right View of above Tree will be: 1, 3, 7
        Top View of above Tree will be: 4, 2, 1, 3, 7
        Bottom View of above Tree will be: 4, 2, 6, 3, 7
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int key;
    int hd; // horizontal distance
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

// left view of tree
/*
    traverse tree from top to bottom , from left to right
    first element on each level comes in left view
*/
void left_view(Node *root)
{
    // do level order traversal and print first node of each level
    if (root != NULL)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL); // for delimiting level

        while (!q.empty())
        {
            Node *temp = q.front();

            if (temp) // for first node on level
            {
                cout << temp->key << ' '; // print key

                while (q.front()) // enqueue next level in queue
                {
                    if (temp->left) // if left child exist
                        q.push(temp->left);

                    if (temp->right) // if right child exist
                        q.push(temp->right);

                    q.pop();
                    temp = q.front();
                }
                q.push(NULL); // push delimiter for next level
            }
            q.pop(); // dequeue NULL delimiter of previous level
        }
    }
}

// right view of tree
/*
    Same as left view , only difference is that we are traversing
    top to bottom , from right to left
*/
void right_view(Node *root)
{
    if (root) // if root is not NULL then only do
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL); // delimiter for level

        while (!q.empty())
        {
            Node *temp = q.front();

            if (temp)
            {
                cout << temp->key << ' ';
                while (q.front())
                {
                    if (temp->right) // this time push right child first
                        q.push(temp->right);

                    if (temp->left)
                        q.push(temp->left);

                    q.pop();
                    temp = q.front();
                }
                q.push(NULL);
            }
            q.pop();
        }
    }
}

/*
    Top View: Top view of a binary tree is the set of nodes visible 
    when the tree is viewed from the top. A node x is there in output 
    if x is the topmost node at its horizontal distance. Horizontal 
    distance of left child of a node x is equal to the horizontal 
    distance of x minus 1, 
    and that of right child is the horizontal distance of x plus 1.
*/
void top_view(Node *root)
{
    if (root)
    {
        queue<Node *> q;
        map<int, int> m;

        int hd = 0;
        root->hd = hd;

        q.push(root);

        while (!q.empty())
        {
            root = q.front();
            hd = root->hd;

            // if not encounter before
            if (m.count(hd) == 0)
                m[hd] = root->key;

            // if left child exist
            if (root->left)
            {
                root->left->hd = hd - 1;
                q.push(root->left);
            }

            // if right child exist
            if (root->right)
            {
                root->right->hd = hd + 1;
                q.push(root->right);
            }

            q.pop();
        }

        // print map
        for (auto key = m.begin(); key != m.end(); key++)
            cout << key->second << ' ';
    }
}

/*
    A node x is there in output of if x is the bottom most instead of
    the top most node at its horizonal distance.

    The process of printing the bottom view is almost the same as that 
    of top view with a little modification that while storing the node's 
    data along with a particular horizontal distance in the map, keep 
    updating the node's data in the map for a particular horizontal distance 
    so that the map contains the last node appearing with a particular horizontal 
    distance instead of first.
*/
void bottom_view(Node *root)
{
    if (root)
    {
        queue<Node *> q;
        map<int, int> m;

        int hd = 0;
        root->hd = hd;

        q.push(root);

        while (!q.empty())
        {
            root = q.front();
            hd = root->hd;

            m[hd] = root->key;

            // if left child exist
            if (root->left)
            {
                root->left->hd = hd - 1;
                q.push(root->left);
            }

            // if right child exist
            if (root->right)
            {
                root->right->hd = hd + 1;
                q.push(root->right);
            }

            q.pop();
        }

        // print map
        for (auto key = m.begin(); key != m.end(); key++)
            cout << key->second << ' ';
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);


    cout << "\nLeft view of the Tree : ";
    left_view(root);
    cout << "\nright view of the Tree : ";
    right_view(root);
    cout << "\ntop view of the Tree : ";
    top_view(root);
    cout << "\nbottom view of the Tree : ";
    bottom_view(root);

    return 0;
}