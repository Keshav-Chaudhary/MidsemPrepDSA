#include <iostream>

using namespace std;

// Define the structure of a node in the BST
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
Node* insert(Node* root, char data) {
    if (root == nullptr)
        return new Node(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to perform post-order traversal of the BST
void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, char key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    // Create the initial BST
    Node* root = nullptr;
    char nodes[] = {'G', 'D', 'I', 'B', 'F', 'J', 'H', 'A', 'C', 'E'};
    for (char node : nodes)
        root = insert(root, node);

    cout << "Post-order traversal before deletion: ";
    postOrderTraversal(root);
    cout << endl;

    // Delete node D
    root = deleteNode(root, 'D');

    cout << "Post-order traversal after deletion: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
