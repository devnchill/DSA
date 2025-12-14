/*
144. Binary Tree Preorder Traversal
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the preorder traversal of its nodes'
values.

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
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
  void traverse(TreeNode *root, vector<int> &res) {
    if (!root)
      return;
    res.push_back(root->val);
    traverse(root->left, res);
    traverse(root->right, res);
  }

public:
  vector<int> res;
  vector<int> preorderTraversal(TreeNode *root) {
    if (!root)
      return {};
    traverse(root, res);
    return res;
  }
};

// Iterative approach
class Solution2 {
private:
  void traverse(TreeNode *root, vector<int> &res) {
    if (!root)
      return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *curr = st.top();
      st.pop();
      res.push_back(curr->val);
      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);
    }
  }

public:
  vector<int> res;
  vector<int> preorderTraversal(TreeNode *root) {
    if (!root)
      return {};
    traverse(root, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution2 s;
  TreeNode *t = new TreeNode(2, new TreeNode(2), new TreeNode(3));
  s.preorderTraversal(t);
  return 0;
}
