/*********************************************************/
/*    Binary Search Tree (BST) - Min and Max Value       */
/*********************************************************/

#include<iostream>
using namespace  std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node() {}
    
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right= NULL;
    }
};


Node* Create(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void InOrder(Node* root)
{
    if(!root)
        return;
    
    InOrder(root->left);    
    cout << root->data << " ";
    InOrder(root->right);
}


Node* Insertion(Node* root, int item)
{
    if(!root)
        return Create(item);
        
    if(item < root->data)
        root->left = Insertion(root->left, item);
    else
        root->right = Insertion(root->right, item);
        
    return root;    
}


int MinValue(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    
    return root->data;
}


int MaxValue(Node *root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    
    return root->data;
}


int main()
{
    Node* root = NULL;
    
    root = Insertion(root, 25);
    root = Insertion(root, 05);
    root = Insertion(root, 40);
    root = Insertion(root, 10);
    root = Insertion(root, 50);
    root = Insertion(root, 35);
    root = Insertion(root, 15);
    root = Insertion(root, 30);
    root = Insertion(root, 20);
    root = Insertion(root, 45);
    
    cout << "Original BST: ";
    InOrder(root);
    cout << endl;
    
    cout << "Min Value of BST: " << MinValue(root) << endl;
    
    cout << "Max Value of BST: " << MaxValue(root) << endl;
    
    return 0;   
}


