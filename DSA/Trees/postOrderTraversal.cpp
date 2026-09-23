#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(4);

    root->left->left = new Node(8);
    root->left->right = new Node(9);

    root->right->left = new Node(7);
    root->right->right = new Node(1);

    root->right->left->left = new Node(5);
    root->right->left->right = new Node(6);

    return 0;
}
