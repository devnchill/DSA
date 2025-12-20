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
    stack<TreeNode *> st;
    TreeNode *last_visited = nullptr;
    TreeNode *curr = root;
    while (!st.empty() || curr) {
      if (curr) {
        st.push(curr);
        curr = curr->left;
      } else {
        TreeNode *node = st.top();
        if (node->right && node->right != last_visited) {
          node = curr->right;
        } else {
          res.push_back(node->val);
          last_visited = node;
          st.pop();
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution2 s;
  TreeNode *left_left = new TreeNode(-1);
  TreeNode *left_right = new TreeNode(0);
  TreeNode *left = new TreeNode(1, left_left, left_right);
  TreeNode *right = new TreeNode(2);
  TreeNode *root = new TreeNode(3, left, right);
  auto res = s.postorderTraversal(root);
  for (int &val : res)
    cout << val << "\n";
  return 0;
}
