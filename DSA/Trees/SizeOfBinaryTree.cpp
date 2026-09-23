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
int countSize(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countSize(root->left) + countSize(root->right);
}

void countSizeMethodTwo(Node *root, int &count)
{
    if (root == nullptr)
        return ;
    count = count + 1;
    countSizeMethodTwo(root->left,count);
    countSizeMethodTwo(root->right,count);

}

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

    int size = countSize(root);
    cout << "Size of the Binary Tree without Count Method 1 : " << size << endl;
    int count = 0;
    countSizeMethodTwo(root, count);

    cout << "Size of the Binary Tree with Count Var Method Second : " << count << endl;
    return 0;
}
