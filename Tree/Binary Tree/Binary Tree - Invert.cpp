/**********************************************/
/*        Binary Tree - Invert Tree           */
/**********************************************/

#include <iostream>
#include <queue>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


Node* Create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void PreOrder(Node* root)
{
    if(!root)
        return;
        
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


Node* InvertTree(Node* root)
{
    if(!root)
        return NULL;
        
    InvertTree(root->left);
    InvertTree(root->right);
    
    swap(root->left, root->right);

    return root;
}


int main()
{
    Node* root = Create(1);
    root->left = Create(2);
    root->right = Create(3);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right->left = Create(6);
    root->right->right = Create(7);

    cout << "Original Tree : ";
    PreOrder(root);
    cout << endl;

    root = InvertTree(root);

    cout << "Invert Tree   : ";
    PreOrder(root);

    return 0;
}

