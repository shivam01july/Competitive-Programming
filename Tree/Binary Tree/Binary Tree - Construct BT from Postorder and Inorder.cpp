/***********************************************************/
/*  Binary Tree - Construct BT from Postorder and Inorder  */
/***********************************************************/

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
        
    InOrder(root->left);
    InOrder(root->right);   
    cout << root->data << " ";
}


Node* construct(int start, int end, vector<int>& postorder, int& pIndex, unordered_map<int, int>& map)
{
    // Base case
    if(start > end)
        return NULL;
        
    // The next element in preorder[] will be the root node of subtree
    // formed by sequence represented by inorder[start, end]    
    Node* root = new Node(postorder[pIndex--]);
    
    // Get the root node index in sequence inorder[] to determine the
    // left and right subtree boundary
    int index = map[root->data];
 
    // Recursively construct the right subtree
    root->right = construct(index + 1, end, postorder, pIndex, map);
    
    // Recursively construct the left subtree
    root->left = construct(start, index - 1, postorder, pIndex, map);
    
    // return current node
    return root;
}


Node* constructTree(vector<int> inorder, vector<int> postorder)
{
    // Get the total number of nodes in the tree
    int n = inorder.size();
    
    // Create a map to efficiently find the index of any element in a given inorder sequence
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;
    
    // `pIndex` stores the index of the next unprocessed node in preorder
    // Start with the root node (present at 0th index)
    int pIndex = n - 1;
    
    return construct(0, n-1, postorder, pIndex, map);
}


int main()
{
    vector<int> inorder   = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> postorder = { 4, 2, 7, 8, 5, 6, 3, 1 };
    
    Node* root = constructTree(inorder, postorder);

    cout << "In Order Tree    : ";
    InOrder(root);
    
    cout << endl;
    
    cout << "Pre Order Tree   : ";
    PostOrder(root);
    
    return 0;
}




