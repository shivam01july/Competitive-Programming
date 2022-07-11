/****************************************************************************/
/*   Traversing Binary Tree - Level Order, Pre Order, In Order, Post Order  */
/****************************************************************************/

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


void LevelOrder(Node* root)
{
    if(!root)
        return;
        
    queue<Node*> queue_t;
    queue_t.push(root);
    
    while(!queue_t.empty())
    {
        Node* current = queue_t.front();
        cout << current->data << " ";
        if(current->left != NULL)
            queue_t.push(current->left);
        if(current->right != NULL)
            queue_t.push(current->right);
        queue_t.pop();    
    }
}


void PreOrder(Node* root)
{
    if(!root)
        return;
        
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


void InOrder(Node* root)
{
    if(!root)
        return;
        
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);    
}


void PostOrder(Node* root)
{
    if(!root)
        return;
        
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
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

    cout << endl << "Level Order Tree : ";
    LevelOrder(root);

    cout << endl << "Pre Order Tree   : ";
    PreOrder(root);
    
    cout << endl << "In Order Tree    : ";
    InOrder(root);
    
    cout << endl << "Post Order Tree  : ";
    PostOrder(root);


    return 0;
}

