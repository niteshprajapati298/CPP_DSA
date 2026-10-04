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
int findHeight(Node* root){
    if(root==nullptr){
      return 0;
    }
    return 1 + max(findHeight(root->left),findHeight(root->right));
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

    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);
    root->right->left->left->left = new Node(12);
    root->right->left->right->right = new Node(13);
   
    int height = findHeight(root);
   cout << "Height of the Binary Tree is " << height << endl;

    return 0;
}
