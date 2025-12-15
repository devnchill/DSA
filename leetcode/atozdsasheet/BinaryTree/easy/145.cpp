/*
145. Binary Tree Postorder Traversal
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the postorder traversal of its nodes'
values.

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

Constraints:

The number of the nodes in the tree is in the range [0, 100].
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

// Recursive approach
class Solution {
private:
  void traversal(vector<int> &res, TreeNode *curr) {
    if (!curr)
      return;
    traversal(res, curr->left);
    traversal(res, curr->right);
    res.push_back(curr->val);
  }

public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root)
      return {};
    vector<int> res;
    traversal(res, root);
    return res;
  }
};

// Iterative approach
class Solution2 {

public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root)
      return {};
    vector<int> res;
    return res;
  }
};
