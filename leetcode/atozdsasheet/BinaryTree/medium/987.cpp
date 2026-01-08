/*
987. Vertical Order Traversal of a Binary Tree
Hard
Topics
premium lock icon
Companies
Given the root of a binary tree, calculate the vertical order traversal of the
binary tree.

For each node at position (row, col), its left and right children will be at
positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of
the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom
orderings for each column index starting from the leftmost column and ending on
the rightmost column. There may be multiple nodes in the same row and same
column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
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
private:
  vector<tuple<int, int, int>> v;
  void traverse(int row, int col, TreeNode *root) {
    if (!root)
      return;
    v.push_back({col, row, root->val});
    if (root->left) {
      traverse(row + 1, col - 1, root->left);
    }
    if (root->right) {
      traverse(row + 1, col + 1, root->right);
    }
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    traverse(0, 0, root);
    sort(v.begin(), v.end());
    vector<vector<int>> res;
    res.push_back({get<2>(v[0])});
    for (int i = 1; i < v.size(); i++) {
      if (get<0>(v[i]) == get<0>(v[i - 1])) {
        res.back().push_back(get<2>(v[i]));
      } else {
        res.push_back({get<2>(v[i])});
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *l1 = new TreeNode(4);
  TreeNode *l2 = new TreeNode(5);
  TreeNode *r1 = new TreeNode(6);
  TreeNode *r2 = new TreeNode(7);
  TreeNode *left = new TreeNode(2, l1, r1);
  TreeNode *right = new TreeNode(3, l2, r2);
  TreeNode *root = new TreeNode(1, left, right);
  auto res = s.verticalTraversal(root);
  for (auto val : res) {
    for (int v : val) {
      cout << v << ",";
    }
    cout << "\n";
  }
  return 0;
}
