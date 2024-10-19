#include<iostream>
#include<vector>
/*BASIC TREE*/
class BinaryTree
{
private:
    std::vector<int> myVec;
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        
        Node(int value) : data(value), left(nullptr), right(nullptr){}
    };
    Node* root;
    
    Node* insert(Node* node, int value)
    {
        if(node  == nullptr)
        {
            return  new Node(value);
        }
        if(value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if(value > node->data)
        {
            node->right = insert(node->right, value);
        }
        return node;

    }
    // HERE IS THE INORDER IMPLEMENTATION
    void inorder(Node* node)
    {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout<<node->data;
        inorder(node->right);
    }
    

public:
    BinaryTree() : root(nullptr) {}
    void insert(int value)
    {
        root = insert(root, value);
    }
    void inorder()
    {
        inorder(root);
        std::cout<<std::endl;
    }


};

int main()
{
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(15);
    tree.insert(25);
    tree.inorder();

    return 0;
}