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

void countNonLeafNode(Node* root, int &count){
    if(root==nullptr) return;
    if(root->left !=nullptr || root->right != nullptr){
           count = count +1;
    }
    countNonLeafNode(root->left,count);
    countNonLeafNode(root->right,count);
}

int countNonLeafNodeM2(Node* root){
    if(root==nullptr) return 0;
    if(root->left ==nullptr && root->right == nullptr){
          return 0;
    }
    return (1 + countNonLeafNodeM2(root->left) + countNonLeafNodeM2(root->right));
  
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
    
    int countofNonLeafNodeM1 = 0;
    countNonLeafNode(root,countofNonLeafNodeM1);
    cout << "Count of Non Leaf Node in Binary Tree With M1 " << countofNonLeafNodeM1 << endl;
     
    int countofNonLeafNodeWithM2 = countNonLeafNodeM2(root);
    cout << "Count of Non Leaf Node With M2 in Binary Tree " << countofNonLeafNodeWithM2 << endl;
    return 0;
}
