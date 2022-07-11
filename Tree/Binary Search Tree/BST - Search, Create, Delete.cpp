/*********************************************************/
/*    Binary Search Tree (BST) - Search, Insert, Delete  */
/*********************************************************/

#include <iostream>
using namespace std;


typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


void InOrder(Node* root)
{
    if(!root)
        return;
    
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}


Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}


Node* minValueNode(Node* current)
{
    /* Loop down to find the leftmost leaf */
    while(current->left != NULL)
        current = current->left;
        
    return current;    
}


Node* Searching(Node* root, int item)
{
    if(root == NULL || root->data == item)
        return root;
        
    if(item < root->data)
        return Searching(root->left, item);
    else
        return Searching(root->right, item);
}


Node* Insertion(Node* root, int item)
{
    /* If the tree is empty, return a new node */
    if(!root)
        return create(item);
    
    /* Otherwise, recur down the tree */
    if(item < root->data)
        root->left = Insertion(root->left, item);
    else
        root->right = Insertion(root->right, item);
    
    /* Return the (unchanged) node pointer */
    return root;
}


Node* Deletion(Node* root, int key)
{
    /* Base case */
    if(!root)
        return root;
        
    /* If key is smaller than root key, then it lies in left subtree */
    if(key < root->data)
        root->left = Deletion(root->left, key);
    
    /* If key is greater than root key, then it lies in right subtree */
    else if(key > root->data)
        root->right = Deletion(root->right, key);
        
    /* If key is same as root key, then this is the node to be deleted */    
    else
    {
        /* If node has no child */
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }    
        
        /* If node has only one child which is in right leaf */    
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        /* If node has only one child which is in left leaf */
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        /* Node has two child */
        /* Get inorder successor (smalles in the right subtree) */
        Node* temp = minValueNode(root->right);
        
        /* Copy the inorder successor content to current root node */
        root->data = temp->data;
        
        /* Delete the inorder successor */
        root->right = Deletion(root->right, temp->data);
    }
    
    return root;
}


int main()
{
    Node* root = NULL;
   
    /* Inserting node into tree */
    root = Insertion(root, 25);
    root = Insertion(root, 15);
    root = Insertion(root, 05);
    root = Insertion(root, 20);
    root = Insertion(root, 30);
    root = Insertion(root, 10);
    root = Insertion(root, 45);
    root = Insertion(root, 40);
    root = Insertion(root, 50);
    root = Insertion(root, 35);
    
    /* Printing the tree */
    InOrder(root);
    cout << endl;
    
    /* Deleting node into tree */
    root = Deletion(root, 5);
    root = Deletion(root, 55);
    root = Deletion(root, 25);
    root = Deletion(root, 50);
    
    /* Printing the tree */
    InOrder(root);

    return 0;
}
