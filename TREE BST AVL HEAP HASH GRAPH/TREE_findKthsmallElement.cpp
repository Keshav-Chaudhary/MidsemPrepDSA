/*
Given a root of a binary tree, find the kth smallest element in the tree.
Input:
       3
     /   \
   1     4
     \
      2

k = 1
Output: 1
Explanation: The smallest element in the binary tree is 1.

Input:
      5
    /   \
   3    6
  /   \
 2    4

k = 3
Output: 4
Explanation: The third smallest element in the binary tree is 4.

Input:
      5
    /   \
   3    6
  /   \
 2    4

k = 5
Output:6
Explanation: There are only 5 elements in the binary tree. Since k is equal to the total number of elements, the kth smallest element becomes the largest element, which is 6
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inOrder(TreeNode* root, vector<int>& elements) {
    if (root == nullptr) return;
    
    inOrder(root->left, elements);
    elements.push_back(root->val);
    inOrder(root->right, elements);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> elements;
    inOrder(root, elements);
    
    if (k >= 1 && k <= elements.size()) {
        return elements[k - 1];
    } else {
        return -1; // Handle invalid k
    }
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    cout << "k = 1, Output: " << kthSmallest(root1, 1) << endl;

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);

    cout << "k = 3, Output: " << kthSmallest(root2, 3) << endl;
    cout << "k = 5, Output: " << kthSmallest(root2, 5) << endl;

    return 0;
}
