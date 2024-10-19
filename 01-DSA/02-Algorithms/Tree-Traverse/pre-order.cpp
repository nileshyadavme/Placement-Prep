#include<iostream>

/*implement Nodes for BT*/
class Node
{
public:
    int val;
    Node* left, *right;
    
    // constructor 
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    // pre-order traversal
    void preorder(Node* node)
    {
        if(node == nullptr) return;
        std::cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }
};


int main()
{
    Node* root = new Node(10);
    Node* secNode = new Node(20);
    Node* thirdtNode = new Node(30);
    Node* forthNode = new Node(40);

    root->left = secNode;
    root->right = thirdtNode;
    secNode->right = forthNode;
    root->preorder(root);
    return 0;
}