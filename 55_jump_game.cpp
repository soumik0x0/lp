#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  bool solve(vector<int>& nums, int n, int idx) {
    if (idx == n - 1) return true;

    for (int i = 1; i <= nums[idx]; i++) {
      if (solve(nums, n, idx + 1)) return true;
    }

    return false;
  }

  bool canJump(vector<int>& nums) {
    int n = nums.size();

    return solve(nums, n, 0);
  }
};

class Solution2 {
public:
  int t[10001];
  bool solve(vector<int>& nums, int n, int idx) {
    if (idx == n - 1) return true;

    if (t[idx] != -1) return t[idx];

    for (int i = 1; i <= nums[idx]; i++) {
      if (solve(nums, n, idx + i)) return t[idx] = true;
    }

    return t[idx] = false;
  }

  bool canJump(vector<int>& nums) {
    int n = nums.size();
    memset(t, -1, sizeof(t));
    return solve(nums, n, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << boolalpha << sol1.canJump(nums) << "\n";
    cout << boolalpha << sol2.canJump(nums) << "\n";
  }

  return 0;
}