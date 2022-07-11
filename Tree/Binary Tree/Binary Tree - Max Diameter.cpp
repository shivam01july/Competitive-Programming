/*********************************************************/
/*          Binary Tree - Diameter of Tree               */
/*********************************************************/

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


int height(Node* root)
{
    if(!root)
        return 0;
        
    int left  = height(root->left);
    int right = height(root->right);
        
    return max(left, right) + 1;
}


int diameter(Node* root)
{
    if(!root)
        return 0;
        
    int left  = height(root->left);
    int right = height(root->right);
    
    int leftDia  = diameter(root->left);
    int rightDia = diameter(root->right);
    
    return max(left + right, max(leftDia, rightDia));
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

    cout << "Diameter of Tree: " << diameter(root) << endl;

    return 0;
}

