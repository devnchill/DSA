/*
Given an array of integers preorder, which represents the preorder traversal of
a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with
the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of
Node.left has a value strictly less than Node.val, and any descendant of
Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then
traverses Node.left, then traverses Node.right.
*/

#include <bits/stdc++.h>
#include <climits>
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
  int i = 0;
  TreeNode *build(vector<int> v, int upper) {
    if (i == v.size() || v[i] > upper) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(v[i++]);
    root->left = build(v, root->val);
    root->right = build(v, upper);
    return root;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    return build(preorder, INT_MAX);
  }
};
