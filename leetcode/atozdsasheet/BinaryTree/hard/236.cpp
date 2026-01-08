/*236. Lowest Common Ancestor of a Binary Tree
Medium
Topics
premium lock icon
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in
the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is
defined between two nodes p and q as the lowest node in T that has both p and q
as descendants (where we allow a node to be a descendant of itself).
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// METHOD 1
// 2 vector path_p and path_q
// dfs on p and store its path in p
// dfs on q and store its path in q
// iterate and return first node of separation

class Solution {
private:
  vector<TreeNode *> path_p, path_q;

  bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode *> &path) {
    if (!root)
      return false;
    path.push_back(root);
    if (root == target)
      return true;
    if (dfs(root->left, target, path) || dfs(root->right, target, path))
      return true;
    path.pop_back();
    return false;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    dfs(root, p, path_p);
    dfs(root, q, path_q);
    int i = 0;
    while (i < path_p.size() && i < path_q.size() && path_p[i] == path_q[i]) {
      i++;
    }
    return path_p[i - 1];
  }
};
