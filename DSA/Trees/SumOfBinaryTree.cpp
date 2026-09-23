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

int sum(Node *root)
{
    if (root == nullptr)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}

void sumSecondMethod(Node* root , int &count){
    if(root==nullptr){
        return ;
    }
    count += root->data;
    sumSecondMethod(root->left,count);
    sumSecondMethod(root->right,count);
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
    int sumOfBinaryTree = sum(root);
    cout << "sum : " << sumOfBinaryTree << endl;
    return 0;
}
