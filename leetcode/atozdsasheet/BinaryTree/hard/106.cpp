/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
Topics
premium lock icon
Companies
Given two integer arrays inorder and postorder where inorder is the inorder
traversal of a binary tree and postorder is the postorder traversal of the same
tree, construct and return the binary tree.
 Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
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
  int postorder_index;
  unordered_map<int, int> m;
  TreeNode *recurse(vector<int> &inorder, vector<int> &postorder, int in_left,
                    int in_right) {
    if (in_left > in_right) {
      return nullptr;
    }
    int root_val = postorder[postorder_index--];
    TreeNode *curr = new TreeNode(root_val);
    int inorder_index = m[root_val];
    curr->right = recurse(inorder, postorder, inorder_index + 1, in_right);
    curr->left = recurse(inorder, postorder, in_left, inorder_index - 1);
    return curr;
  };

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    postorder_index = postorder.size() - 1;
    for (int i = 0; i < postorder_index + 1; i++) {
      m[inorder[i]] = i;
    }
    return recurse(inorder, postorder, 0, postorder_index);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> i = {9, 3, 15, 20, 7};
  vector<int> p = {9, 15, 7, 20, 3};
  s.buildTree(i, p);
  return 0;
}
