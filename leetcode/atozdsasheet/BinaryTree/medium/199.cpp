/*
199. Binary Tree Right Side View
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, imagine yourself standing on the right side of
it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]
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
  vector<int> res;
  void traverse(TreeNode *root, int depth) {
    if (!root)
      return;
    int n = res.size();
    if (depth == n)
      res.push_back(root->val);
    traverse(root->right, depth + 1);
    traverse(root->left, depth + 1);
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    traverse(root, 0);
    return res;
  }
};
