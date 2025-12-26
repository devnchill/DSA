/*
101. Symmetric Tree
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
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
  bool mirror(TreeNode *a, TreeNode *b) {
    if (!a && !b)
      return true;
    if (!a || !b)
      return false;
    if (a->val != b->val)
      return false;

    return mirror(a->left, b->right) && mirror(a->right, b->left);
  }

public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return mirror(root->left, root->right);
  }
};
