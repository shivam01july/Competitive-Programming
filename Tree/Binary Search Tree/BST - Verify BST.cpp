/*********************************************************/
/*       Binary Search Tree (BST) - Verify BST           */
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


bool isBST(Node* root, Node* left, Node* right)
{   
    // Base condition
    if(!root)
        return true;
        
    // If left node exist then check it has correct data or not 
    // i.e. left node's data should be less than root's data    
    if(left && left->data >= root->data)
        return false;
    
    // If right node exist then check it has correct data or not 
    // i.e. right node's data should be greater than root's data    
    if(right && right->data <= root->data)
        return false;

    // Check recursively for every node
    return isBST(root->left, left, root) && isBST(root->right, root, right);
}


int main()
{
    Node* root = NULL;
    
    root = Insertion(root, 3);
    root = Insertion(root, 2);
    root = Insertion(root, 5);
    root = Insertion(root, 1);
    root = Insertion(root, 4);
    
    cout << "BST: ";
    InOrder(root);
    cout << endl;
    
    if(isBST(root, NULL, NULL))
        cout << "It is BST" << endl;
    else
        cout << "It is not BST" << endl;
    
    return 0;   
}



