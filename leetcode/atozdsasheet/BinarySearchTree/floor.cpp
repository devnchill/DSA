/*
Floor in a Binary Search Tree

Problem Statement: Given a Binary Search Tree and a key, return the floor of the
given key in the Binary Search Tree. Floor of a value refers to the value of the
largest node in the Binary Search Tree that is smaller than or equal to the
given key. If the floor node does not exist, return nullptr.
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left) : val(val), left(left), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution {
public:
  int get_floor(TreeNode *root, int key) {
    int ceil = -1;
    while (root) {
      if (root->val == key)
        return root->val;
      if (root->val <= key) {
        ceil = root->val;
        root = root->right;
      } else {
        root = root->left;
      }
    }
    return ceil;
  }
};
