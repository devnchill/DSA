/*
297. Serialize and Deserialize Binary Tree
Hard
Topics
premium lock icon
Companies
Serialization is the process of converting a data structure or object into a
sequence of bits so that it can be stored in a file or memory buffer, or
transmitted across a network connection link to be reconstructed later in the
same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no
restriction on how your serialization/deserialization algorithm should work. You
just need to ensure that a binary tree can be serialized to a string and this
string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a
binary tree. You do not necessarily need to follow this format, so please be
creative and come up with different approaches yourself.
*/

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root)
      return "";
    queue<TreeNode *> q;
    q.push(root);
    string result;
    while (!q.empty()) {
      TreeNode *curr = q.front();
      q.pop();
      if (!curr) {
        result += "null,";
        continue;
      }
      result += to_string(curr->val) + ",";
      q.push(curr->left);
      q.push(curr->right);
    }
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty())
      return nullptr;
    stringstream ss(data);
    string token;
    getline(ss, token, ',');
    TreeNode *root = new TreeNode(stoi(token));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *curr = q.front();
      q.pop();
      if (!getline(ss, token, ','))
        break;
      if (token != "null") {
        curr->left = new TreeNode(stoi(token));
        q.push(curr->left);
      }
      if (!getline(ss, token, ','))
        break;
      if (token != "null") {
        curr->right = new TreeNode(stoi(token));
        q.push(curr->right);
      }
    }
    return root;
  }
};
