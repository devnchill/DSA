/*
102. Binary Tree Level Order Traversal
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, return the level order traversal of its nodes'
values. (i.e., from left to right, level by level).
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    TreeNode *curr = root;
    q.push(curr);
    while (!q.empty()) {
      vector<int> temp;
      int no_of_curr_level_nodes = q.size();
      for (int i = 1; i <= no_of_curr_level_nodes; ++i) {
        curr = q.front();
        temp.push_back(curr->val);
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
        q.pop();
      }
      res.push_back(temp);
    }
    return res;
  }
};
