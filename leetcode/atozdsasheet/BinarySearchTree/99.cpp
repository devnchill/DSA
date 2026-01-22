/*
99. Recover Binary Search Tree
Medium
Topics
premium lock icon
Companies
You are given the root of a binary search tree (BST), where the values of
exactly two nodes of the tree were swapped by mistake. Recover the tree without
changing its structure.
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
  TreeNode *first, *second, *prev;
  void inorder(TreeNode *root) {
    if (!root)
      return;
    inorder(root->left);
    if (prev && prev->val > root->val) {
      if (!first) {
        first = prev;
      }
      second = root;
    }
    prev = root;
    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root) {
    inorder(root);
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
  }
};
