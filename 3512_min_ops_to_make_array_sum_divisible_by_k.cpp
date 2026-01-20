#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int sum = 0;

    for (const auto& num : nums) {
      sum += num;
    }

    return (sum % k);
  }
};

class Solution2 {
public:
  int minOperations(vector<int>& nums, int k) {
    return accumulate(nums.begin(), nums.end(), 0) % k;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;
  Solution2 sol2;

  int T;
  cin >> T;

  while (T--) {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol.minOperations(nums, k) << "\n";
    cout << sol2.minOperations(nums, k) << "\n";
  }

  return 0;
}