#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    /* data */
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int main()
{
    struct Node* root = new Node(1);
    struct Node* left = new Node(2);
    struct Node* right = new Node(3);
    root->left = left;
    root->right = right;


    cout <<"Root -> " << root->data << " " << endl;
    cout <<"Left -> " << root->left->data << " " << endl;
    cout <<"Right -> " << root->right->data << " " << endl;
}