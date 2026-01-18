// Given the root of a binary search tree, and an integer k, return the kth
// smallest value (1-indexed) of all the values of the nodes in the tree.

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
  vector<int> v;
  void inorder(TreeNode *root) {
    if (!root)
      return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    inorder(root);
    return v[k - 1];
  }
};
