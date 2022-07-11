/*********************************************************/
/*  Binary Search Tree (BST) - Predecessor and Successor */
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


void FindPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if(root == NULL)
        return;
    
    // If key is present at root    
    if(key == root->data)
    {
        // The maximum value in left subtree is predecessor
        if(root->left != NULL)
        {
            Node* temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }
            pre = temp;
        }
        
        // The minimum value in right subtree is successor
        if(root->right != NULL)
        {
            Node* temp = root->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            suc = temp;
        }
        
        return;
    }
    
    // If key is smaller than root key, go to left subtree
    if(key < root->data)
    {
        suc = root;
        FindPreSuc(root->left, pre, suc, key);
    }
    
    // If key is greater than root key, go to right subtree
    else
    {
        pre = root;
        FindPreSuc(root->right, pre, suc, key);
    }
}


Node* FindPredecessor(Node* root, int key)
{
    if(!root)
        return NULL;
    
    static Node* pre = NULL;
    
    if(key == root->data)
    {
        // The maximum value in left subtree is predecessor
        if(root->left)
        {
            Node* temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }
        return pre;
    }
    
    // If key is smaller than root key, go to left subtree
    if(key < root->data)
        root =  FindPredecessor(root->left, key);
        
    // If key is greater than root key, go to right subtree    
    else if(key > root->data)
    {
        pre = root;
        root = FindPredecessor(root->right, key);
    }
    
    return pre;
}


Node* FindSuccessor(Node* root, int key)
{
    if(!root)
        return NULL;
    
    static Node* suc = NULL;
    
    if(key == root->data)
    {
        // The minimum value in right subtree is successor
        if(root->right)
        {
            Node* temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;    
        }
        return suc;
    }
    
    // If key is smaller than root key, go to left subtree
    if(key < root->data)
    {
        suc = root;
        root = FindSuccessor(root->left, key);
    }
    
    // If key is greater than root key, go to right subtree
    else if(key > root->data)
        root =  FindSuccessor(root->right, key);
    
    return suc;
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
    
    cout << "BST: ";
    InOrder(root);
    cout << endl;
    
    int key;
    Node* pre;
    Node* suc;
    
    key = 25;
    pre = NULL;
    suc = NULL;
    FindPreSuc(root, pre, suc, key);
    cout << "Key: " << key << " :: ";
    if(pre != NULL)
        cout << "Predecessor: " << pre->data;
    else
        cout << "Predecessor: NA";
    cout << " , ";
    if(suc != NULL)
        cout << "Successor: " << suc->data;
    else
        cout << "Successor: NA";
    cout << endl;
    
    
    key = 5;
    pre = NULL;
    suc = NULL;
    pre = FindPredecessor(root, key);
    suc = FindSuccessor(root, key);
    cout << "Key: " << key << " :: ";
    if(pre != NULL)
        cout << "Predecessor: " << pre->data;
    else
        cout << "Predecessor: NA";
    cout << " , ";
    if(suc != NULL)
        cout << "Successor: " << suc->data;
    else
        cout << "Successor: NA";
    cout << endl;

    key = 50;
    pre = NULL;
    suc = NULL;
    pre = FindPredecessor(root, key);
    suc = FindSuccessor(root, key);
    cout << "Key: " << key << " :: ";
    if(pre != NULL)
        cout << "Predecessor: " << pre->data;
    else
        cout << "Predecessor: NA";
    cout << " , ";
    if(suc != NULL)
        cout << "Successor: " << suc->data;
    else
        cout << "Successor: NA";
    cout << endl;

    
    
    key = 75;
    pre = FindPredecessor(root, key);
    suc = FindSuccessor(root, key);
    cout << "Key: " << key << " :: ";
    if(pre != NULL)
        cout << "Predecessor: " << pre->data;
    else
        cout << "Predecessor: NA";
    cout << " , ";
    if(suc != NULL)
        cout << "Successor: " << suc->data;
    else
        cout << "Successor: NA";
    cout << endl;
    
    return 0;   
}

