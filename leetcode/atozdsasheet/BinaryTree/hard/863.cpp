/*
863. All Nodes Distance K in Binary Tree
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, the value of a target node target, and an
integer k, return an array of the values of all nodes that have a distance k
from the target node.

You can return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  vector<int> v;
  vector<int> r;

  bool get_target_path(TreeNode *root, TreeNode *target) {
    if (!root)
      return false;
    v.push_back(root->val);
    if (root == target)
      return true;
    if (get_target_path(root->left, target) ||
        get_target_path(root->right, target))
      return true;
    v.pop_back();
    return false;
  }

  void target_depth(TreeNode *root, int depth, int k) {
    if (!root)
      return;
    if (depth == k) {
      r.push_back(root->val);
      return;
    }
    target_depth(root->left, depth + 1, k);
    target_depth(root->right, depth + 1, k);
  }

  void collect_from_ancestor(TreeNode *ancestor, int dist_to_target, int k,
                             TreeNode *block) {
    if (!ancestor || ancestor == block)
      return;
    target_depth(ancestor, dist_to_target + 1, k);
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    v.clear();
    r.clear();
    get_target_path(root, target);
    int len = v.size();
    target_depth(target, 0, k);
    TreeNode *curr = root;
    for (int i = 0; i < len - 1; i++) {
      int dist_to_target = len - 1 - i;
      if (dist_to_target == k) {
        r.push_back(v[i]);
      }
      curr = root;
      for (int j = 1; j <= i; j++) {
        if (curr->left && curr->left->val == v[j])
          curr = curr->left;
        else
          curr = curr->right;
      }
      TreeNode *block = (curr->left && curr->left->val == v[i + 1])
                            ? curr->left
                            : curr->right;
      collect_from_ancestor(curr->left, dist_to_target, k, block);
      collect_from_ancestor(curr->right, dist_to_target, k, block);
    }

    return r;
  }
};

void freeTree(TreeNode *node) {
  if (!node)
    return;
  freeTree(node->left);
  freeTree(node->right);
  delete node;
}

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *target_left = new TreeNode(7);
  TreeNode *target_right = new TreeNode(8);
  TreeNode *target = new TreeNode(2, target_left, target_right);
  TreeNode *root_right = new TreeNode(5);
  TreeNode *root = new TreeNode(1, target, root_right);
  auto res = s.distanceK(root, target_left, 1);
  for (auto &val : res) {
    cout << val << ", ";
  }
  freeTree(root);
  return 0;
}
