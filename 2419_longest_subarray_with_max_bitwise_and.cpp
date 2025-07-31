#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int maxValue = 0;
    int streak = 0;
    int result = 0;

    for (const auto& num : nums) {
      if (num > maxValue) {
        maxValue = num;
        streak = 0;
        result = 0;
      }

      if (num == maxValue) {
        streak++;
      } else {
        streak = 0;
      }

      result = max(result, streak);
    }

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol.longestSubarray(nums) << "\n";
  }

  return 0;
}