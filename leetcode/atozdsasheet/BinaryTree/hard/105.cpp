/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
Topics
premium lock icon
Companies
Given two integer arrays preorder and inorder where preorder is the preorder
traversal of a binary tree and inorder is the inorder traversal of the same
tree, construct and return the binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

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
private:
  unordered_map<int, int> m;
  int preorder_index = 0;

  TreeNode *recurse(vector<int> &preorder, int in_left, int in_right) {
    if (in_left > in_right)
      return nullptr;

    int root_val = preorder[preorder_index++];
    TreeNode *root = new TreeNode(root_val);
    int inorder_index = m[root_val];
    root->left = recurse(preorder, in_left, inorder_index - 1);
    root->right = recurse(preorder, inorder_index + 1, in_right);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      m[inorder[i]] = i;
    }
    return recurse(preorder, 0, inorder.size() - 1);
  }
};
;
