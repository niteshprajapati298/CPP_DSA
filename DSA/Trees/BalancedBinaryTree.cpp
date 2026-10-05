#include <iostream>
#include <cmath>
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

int findHeight(Node *root, bool &isBalanced)
{
    if (root == NULL)
        return 0;

    int leftHeight = findHeight(root->left, isBalanced);
    int rightHeight = findHeight(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node *root)
{
    bool balanced = true;
    findHeight(root, balanced);
    return balanced;
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

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    cout << "Balanced: " << boolalpha << isBalanced(root) << endl;

    return 0;
}