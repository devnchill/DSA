/*
103. Binary Tree Zigzag Level Order Traversal
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the zigzag level order traversal of its
nodes' values. (i.e., from left to right, then right to left for the next level
and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root)
      return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;
    bool reverse = false;
    while (!q.empty()) {
      int size = q.size();
      vector<int> temp(size);
      for (int i = 0; i < size; i++) {
        TreeNode *curr = q.front();
        q.pop();
        int idx = reverse ? size - 1 - i : i;
        temp[idx] = curr->val;
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
      res.push_back(temp);
      reverse = !reverse;
    }
    return res;
  }
};
;
int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root3 = new TreeNode(15);
  TreeNode *root4 = new TreeNode(7);
  TreeNode *root5 = new TreeNode(20, root3, root4);
  TreeNode *root2 = new TreeNode(9);
  TreeNode *root1 = new TreeNode(3, root2, root5);
  auto res = s.zigzagLevelOrder(root1);
  for (auto v : res) {
    for (int val : v) {
      cout << val << ", ";
    }
    cout << "\n";
  }
  return 0;
}
