#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <stdint.h>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBST(const vector<Node>& tree, int index, long min, long max){

    if(index == -1)
        return true;

    long key = tree[index].key;
    long left_index = tree[index].left;
    long right_index = tree[index].right;

    if(key < min || key > max)
        return false;

    return isBST(tree, left_index, min, key - 1) && isBST(tree, right_index, key, max);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.empty()) return true;

  return isBST(tree, 0, LONG_MIN, LONG_MAX);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
