/*
114. Flatten Binary Tree to Linked List
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child
pointer points to the next node in the list and the left child pointer is always
null. The "linked list" should be in the same order as a pre-order traversal of
the binary tree.
*/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  TreeNode dummy{0};

private:
  void preorder(TreeNode *root, TreeNode *&ll) {
    if (!root) {
      return;
    }
    ll->right = root;
    ll->left = nullptr;
    ll = root;
    preorder(root->left, ll->right);
    preorder(root->right, ll->right);
  }

public:
  void flatten(TreeNode *root) {
    TreeNode *ll = &dummy;
    preorder(root, ll);
  }
};
