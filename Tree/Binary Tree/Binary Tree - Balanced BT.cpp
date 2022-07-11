/*********************************************************/
/*      Binary Tree - Verify Balanced Binary Tree        */
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


bool IsBalanced(Node* root)
{
    if(!root)
        return true;
        
    int left  = height(root->left);
    int right = height(root->right);
    
    bool lBal = IsBalanced(root->left);
    bool rBal = IsBalanced(root->right);
    
    bool diff = abs(left - right) <= 1;
    
    return diff && lBal && rBal;
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

    if(IsBalanced(root))
        cout << "Binary Tree is Balanced" << endl;
    else
        cout << "Binary Tree not is Balanced" << endl;

    return 0;
}


