/*
Problem Statement: Given a Binary Search Tree and a key, return the ceiling of
the given key in the Binary Search Tree. Ceiling of a value refers to the value
of the smallest node in the Binary Search Tree that is greater than or equal to
the given key. If the ceiling node does not exist, return nullptr.
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
  int get_ceiling(TreeNode *root, int key) {
    int ceil = -1;
    while (root) {
      if (root->val == key)
        return root->val;
      if (root->val >= key) {
        ceil = root->val;
        root = root->left;
      } else {
        root = root->right;
      }
    }
    return ceil;
  }
};
void freeTree(TreeNode *node) {
  if (!node)
    return;
  freeTree(node->left);
  freeTree(node->right);
  delete node;
}
int main() {
  TreeNode *ll1 = new TreeNode(4);
  TreeNode *lr1 = new TreeNode(7);
  TreeNode *rl1 = new TreeNode(10);
  TreeNode *rr1 = new TreeNode(14);
  TreeNode *left1 = new TreeNode(5, ll1, lr1);
  TreeNode *right1 = new TreeNode(12, rl1, rr1);
  TreeNode *root = new TreeNode(8, left1, right1);
  Solution s;
  cout << s.get_ceiling(root, 9);
  freeTree(root);
  return 0;
}
