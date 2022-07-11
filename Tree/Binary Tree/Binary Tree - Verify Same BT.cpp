/*********************************************************/
/*        Binary Tree - Verify Same Binary Tree          */
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


bool IsSame(Node* p, Node* q)
{
    if(!p && !q)
        return true;
        
    if(!p || !q)
        return false;
    
    if(p->data != q->data)
        return false;
    
    bool left  = IsSame(p->left, q->left);
    bool right = IsSame(p->right, q->right);
    
    return left && right;
}


int main()
{
    Node* root1 = Create(1);
    root1->left = Create(2);
    root1->right = Create(3);
    root1->left->left = Create(4);
    root1->left->right = Create(5);
    root1->right->left = Create(6);
    root1->right->right = Create(7);

    Node* root2 = Create(1);
    root2->left = Create(2);
    root2->right = Create(3);
    root2->left->left = Create(4);
    root2->left->right = Create(5);
    root2->right->left = Create(6);
    root2->right->right = Create(7);

    if(IsSame(root1, root2))
        cout << "Binary Tree is Same" << endl;
    else
        cout << "Binary Tree not is not Same" << endl;

    return 0;
}



