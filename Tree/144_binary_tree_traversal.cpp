#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> ans;

    solve(root, ans);

    return ans;
  }

  void solve(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    ans.push_back(root->val);
    solve(root->left, ans);
    solve(root->right, ans);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  return 0;
}