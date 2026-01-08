/*
222. Count Complete Tree Nodes
Easy
Topics
premium lock icon
Companies
Given the root of a complete binary tree, return the number of the nodes in the
tree.

According to Wikipedia, every level, except possibly the last, is completely
filled in a complete binary tree, and all nodes in the last level are as far
left as possible. It can have between 1 and 2h nodes inclusive at the last level
h.
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
public:
  int getHeight(TreeNode *node) {
    int h = 0;
    while (node) {
      h++;
      node = node->left;
    }
    return h;
  }

  int countNodes(TreeNode *root) {
    if (!root)
      return 0;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if (lh == rh) {
      // left subtree is perfect
      return (1 << lh) + countNodes(root->right);
    } else {
      // right subtree is perfect
      return (1 << rh) + countNodes(root->left);
    }
  }
};
