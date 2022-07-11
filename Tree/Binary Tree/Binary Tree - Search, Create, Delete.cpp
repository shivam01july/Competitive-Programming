/*********************************************************/
/*        Binary Tree - Search, Insert, Delete           */
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


void InOrder(Node* root)
{
    if(!root)
        return;
    
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}


Node* Searching(Node* root, int key)
{
    if(root == NULL && root->data == key)
        return root;
    
    queue<Node*> queue_t;
    queue_t.push(root);
    
    while(!queue_t.empty())
    {
        Node* current = queue_t.front();
        queue_t.pop();
        
        if(current->data == key)
            return current;
            
        if(current->left != NULL)
            queue_t.push(current->left);
        
        if(current->right != NULL)
            queue_t.push(current->right);
    }

    return NULL;
}


Node* Insertion(Node* root, int item)
{
    if(!root)
        return Create(item);
        
    queue<Node*> queue_t;
    queue_t.push(root);
    
    while(!queue_t.empty())
    {
        Node* current = queue_t.front();
        queue_t.pop();
        
        if(current->left != NULL)
            queue_t.push(current->left);
        else
        {
            current->left = Create(item);
            return root;
        }    
        
        if(current->right != NULL)
            queue_t.push(current->right);
        else
        {
            current->right = Create(item);
            return root;
        }    
    }
    
    return root; 
}


Node* Deletion(Node* root, int key)
{
    if(!root)
        return NULL;
    
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key)
        {
            delete root;
            return NULL;
        }
        else
            return root;
    }
    
        
    queue<Node*> queue_t;
    queue_t.push(root);
    
    Node* key_node = NULL;
    Node* deepest = NULL;
    Node* last = NULL;
    
    while(!queue_t.empty())
    {
        Node* current = queue_t.front();
        queue_t.pop();
        
        if(current->data == key)
        {
            key_node = current;
        }
        
        if(current->left != NULL)
        {
            last = current;
            queue_t.push(current->left);
        }
        
        if(current->right != NULL)
        {
            last = current;
            queue_t.push(current->right);
        }
        
        deepest = current;
    }
    
    if(key_node != NULL)
    {
        key_node->data = deepest->data;
        
        if(last->right != NULL)
            last->right = NULL;
        else
            last->left = NULL;
            
        delete deepest;    
    }
    
    return root;
}


int main()
{
    Node* root = NULL;
    
    /* Basis Insertion */
    root = Create(1);
    root->left = Create(2);
    root->right = Create(3);
    
    /* Single Insertion */
    root = Insertion(root, 4);
    root = Insertion(root, 5);
    root = Insertion(root, 6);
    root = Insertion(root, 7);
    
    /* Loop Insertion */
    for(int i = 8; i <= 15; i++)
    {
        root = Insertion(root, i);
    }
 
    cout << "Insertion : "; 
    InOrder(root);
    cout << endl;
    
    
    /* Deletion */
    root = Deletion(root, 1);
    root = Deletion(root, 8);
    root = Deletion(root, 15);
    
    cout << "Deletion  : ";
    InOrder(root);
    cout << endl;
    
    
    /* Searching */
    Node* temp;
    int key;
    
    key = 5;
    temp = Searching(root, key);
    if(temp)
        cout << "Searching : Found " << temp->data << endl;
    else
        cout << "Searching : Not Found " << key << endl;
    
    key = 21;
    temp = Searching(root, key);
    if(temp)
        cout << "Searching : Found " << temp->data << endl;
    else
        cout << "Searching : Not Found " << key << endl;
    
    return 0;
}
