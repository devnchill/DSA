/*
104. Maximum Depth of Binary Tree
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2


Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
  }
};
;

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  cout << s.maxDepth(root);
  return 0;
}
