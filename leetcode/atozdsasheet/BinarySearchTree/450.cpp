/*
450. Delete Node in a BST
Medium
Topics
premium lock icon
Companies
Given a root node reference of a BST and a key, delete the node with the given
key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return nullptr;

    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      // node found

      // case 1 & 2: zero or one child
      if (!root->left)
        return root->right;
      if (!root->right)
        return root->left;

      // case 3: two children
      TreeNode *succ = root->right;
      while (succ->left)
        succ = succ->left;

      root->val = succ->val;
      root->right = deleteNode(root->right, succ->val);
    }
    return root;
  }
};
