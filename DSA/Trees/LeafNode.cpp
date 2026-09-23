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


void countLeafNodes(Node* root, int &count){
    if(root == nullptr) {
        count = count + 1;
        return;
    }
    countLeafNodes(root->left,count);
    countLeafNodes(root->right,count);


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

    int count = 0;
    countLeafNodes(root,count);
    cout << "Count of Leaf Nodes : " << count << endl;
    return 0;
}
