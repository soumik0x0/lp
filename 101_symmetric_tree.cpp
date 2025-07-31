#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return (left -> val == right -> val) && isMirror(left -> left, right -> right) && isMirror(left -> right, right -> left);
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root -> left, root -> right);
  }
};

TreeNode* buildTree() {
  int val;
  cin >> val;
  if (val == -1) return nullptr;

  TreeNode* root = new TreeNode(val);
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();

    //left child
    cin >> val;
    if (val != -1) {
      curr -> left = new TreeNode(val);
      q.push(curr -> left);
    }

    //right child
    cin >> val;
    if (val != -1) {
      curr -> right = new TreeNode(val);
      q.push(curr -> right);
    }
  }
  return root;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while (t--) {
    TreeNode* root = buildTree();
    cout << boolalpha << sol.isSymmetric(root) << "\n";
  }

  return 0;
}