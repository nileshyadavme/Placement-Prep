#include<iostream>

/*Basic Tree*/
struct Node
{
    int val;
    Node *left, *right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/*Post-order Traversal*/
void postorder(Node* node)
{
    if(node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    std::cout<<node->val<<" ";
}

int main()
{
    Node* root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(12);
    root->left->right = new Node(13);

    postorder(root);

    return 0;
}