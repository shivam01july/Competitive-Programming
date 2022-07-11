/*********************************************************/
/*        Binary Tree - Maximum Depth of Tree            */
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


int DepthOfTree_Rec(Node* root)
{
    if(!root)
        return 0;
        
    int left  = DepthOfTree_Rec(root->left);
    int right = DepthOfTree_Rec(root->right);
        
    return max(left, right) + 1;
}


int DepthOfTree_Que(Node* root)
{
    if(!root)
        return 0;
    
    int depth = 0;
        
    queue<Node*> tree;
    tree.push(root);
        
    while(!tree.empty())
    {
        int size = tree.size();
            
        for(int i = 0; i < size; i++)
        {
            Node* curr = tree.front();
            tree.pop();
            
            if(curr->left)
                tree.push(curr->left);
            
            if(curr->right)
                tree.push(curr->right);
        }
        depth++;
    }
        
    return depth;
}


int main()
{
    Node* root = Create(1);
    root->left = Create(2);
    root->right = Create(3);
    
    cout << "Depth of Tree: " << DepthOfTree_Que(root) << endl;
    
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right->left = Create(6);
    root->right->right = Create(7);

    cout << "Depth of Tree: " << DepthOfTree_Rec(root) << endl;

    return 0;
}
