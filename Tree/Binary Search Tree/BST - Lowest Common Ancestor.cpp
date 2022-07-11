/*********************************************************/
/*    Binary Search Tree (BST) - Lowest Common Ancestor  */
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


Node* Ancestor(Node* root, int n1, int n2)
{
    if(!root)
        return NULL;
        
    if(root->data > n1 && root->data > n2)
        return Ancestor(root->left, n2, n2);
    
    if(root->data < n1 && root->data < n2)
        return Ancestor(root->right, n2, n2);    

    return root;
}


Node* Ancestor2(Node* root, int n1, int n2)
{
    if(!root)
        return NULL;
        
    if(n1 == root->data || n2 == root->data)
        return root;
        
    Node* left = Ancestor2(root->left, n1, n2);
    Node* right = Ancestor2(root->right, n1, n2);
        
    if(!right)
        return left;
        
    if(!left)
        return right;

    return root;
}


int main()
{
    Node* root = NULL;
    
    root = Insertion(root, 20);
    root = Insertion(root, 8);
    root = Insertion(root, 22);
    root = Insertion(root, 04);
    root = Insertion(root, 12);
    root = Insertion(root, 10);
    root = Insertion(root, 14);
    
    cout << "BST: ";
    InOrder(root);
    cout << endl;
    
    int n1;
    int n2;
    Node* res; 
    
    n1 = 10;
    n2 = 14;
    res = Ancestor(root, n1, n2);
    cout << "Lowest Common Ancestor of " << n1 << " & " << n2 << " : " << res->data << endl;

    n1 = 14;
    n2 = 8;
    res = Ancestor(root, n1, n2);
    cout << "Lowest Common Ancestor of " << n1 << " & " << n2 << " : " << res->data << endl;
    
    n1 = 10;
    n2 = 22;
    res = Ancestor2(root, n1, n2);
    cout << "Lowest Common Ancestor of " << n1 << " & " << n2 << " : " << res->data << endl;
    
    return 0;   
}



