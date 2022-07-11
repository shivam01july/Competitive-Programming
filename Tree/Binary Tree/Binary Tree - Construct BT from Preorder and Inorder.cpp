/**********************************************************/
/*  Binary Tree - Construct BT from Preorder and Inorder  */
/**********************************************************/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node() {};
    
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


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


Node* construct(int start, int end, vector<int>& preorder, int& pIndex, unordered_map<int, int>& map)
{
    // Base case
    if(start > end)
        return NULL;
        
    // The next element in preorder[] will be the root node of subtree
    // formed by sequence represented by inorder[start, end]    
    Node* root = new Node(preorder[pIndex++]);
    
    // Get the root node index in sequence inorder[] to determine the
    // left and right subtree boundary
    int index = map[root->data];
    
    // Recursively construct the left subtree
    root->left = construct(start, index - 1, preorder, pIndex, map);
    
    // Recursively construct the right subtree
    root->right = construct(index + 1, end, preorder, pIndex, map);
    
    // return current node
    return root;
}


Node* constructTree(vector<int> inorder, vector<int> preorder)
{
    // Get the total number of nodes in the tree
    int n = inorder.size();
    
    // Create a map to efficiently find the index of any element in a given inorder sequence
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;
    
    // `pIndex` stores the index of the next unprocessed node in preorder
    // Start with the root node (present at 0th index)
    int pIndex = 0;
    
    return construct(0, n-1, preorder, pIndex, map);
}


int main()
{
    vector<int> inorder   = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> preorder  = { 1, 2, 4, 3, 5, 7, 8, 6 };
    
    Node* root = constructTree(inorder, preorder);

    cout << "In Order Tree    : ";
    InOrder(root);
    
    cout << endl;
    
    cout << "Pre Order Tree   : ";
    PreOrder(root);
    
    return 0;
}



