#include <iostream>
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(int d) : data(d), left(nullptr), right(nullptr) {}
  Node(int d, Node *left, Node *right) : data(d), left(left), right(right) {}
};

int main(int argc, char *argv[]) {
  Node *binary_tree = new Node(1);
  binary_tree->left = new Node(2);
  binary_tree->right = new Node(3);
  std::cout << binary_tree->left->data << binary_tree->data
            << binary_tree->right->data << "\n";
  return 0;
}
