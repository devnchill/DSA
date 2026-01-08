/*
662. Maximum Width of Binary Tree
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the
leftmost and rightmost non-null nodes), where the null nodes between the
end-nodes that would be present in a complete binary tree extending down to that
level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
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
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;
    unsigned long long width = 0;
    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
      width = max(width, q.back().second - q.front().second + 1);
      int len = q.size();
      unsigned long long base = q.front().second;
      for (int i = 0; i < len; i++) {
        auto [node, idx] = q.front();
        q.pop();
        idx -= base;
        if (node->left)
          q.push({node->left, 2 * idx + 1});
        if (node->right)
          q.push({node->right, 2 * idx + 2});
      }
    }
    return (int)width;
  }
};
