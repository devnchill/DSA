/*
653. Two Sum IV - Input is a BST
Easy
Topics
premium lock icon
Companies
Given the root of a binary search tree and an integer k, return true if there
exist two elements in the BST such that their sum is equal to k, or false
otherwise.
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

// METHOD 1 INORDER FOR GETTING VALS IN SORTED ORDER
class Solution {
private:
  vector<int> vals;
  void inorder(TreeNode *root) {
    if (!root)
      return;
    inorder(root->left);
    vals.push_back(root->val);
    inorder(root->right);
  }

public:
  bool findTarget(TreeNode *root, int k) {
    inorder(root);
    int start = 0, end = vals.size() - 1;
    while (start < end) {
      int sum = vals[start] + vals[end];
      if (sum == k)
        return true;
      if (sum > k)
        end--;
      else
        start++;
    }
    return false;
  }
};
