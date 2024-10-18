#include<iostream>

// Structure of each node
class BinaryTree
{
private:
    // define the structure of a tee node
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        // constructor for Node
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; // Root of the binary tree

        // Private helper functions (recursive implementations)
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); 
        }

        if (value < node->data) {
            node->left = insert(node->left, value);  // Insert into left subtree
        } else if (value > node->data) {
            node->right = insert(node->right, value); // Insert into right subtree
        }
        return node; // Return the updated node pointer
    }


    // inorder
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left); // Visit left subtree
        std::cout << node->data << " "; // Visit current node
        inorder(node->right); // Visit right subtree
    }
    void deleteTree(Node* node)
    {
        if(node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    // constructor
    BinaryTree() : root(nullptr) {}

    // insert
    void insert(int value)
    {
        root = insert(root, value);
    }

    void inorder()
    {
        inorder(root);
        std::cout<<std::endl;

    }
    ~BinaryTree()
    {
        deleteTree(root);
    }
};


int main()
{
    BinaryTree tree;
    
    // Insert nodes into the binary tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(15);
    tree.insert(25);

    // Perform various traversals
    std::cout << "Inorder Traversal: ";
    tree.inorder();
    return 0;
}