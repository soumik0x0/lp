#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int maxOnes = 0;
    int count = 0;

    for (const auto& num : nums) {
      if (num == 1) {
        count++;
        maxOnes = max(maxOnes, count);
      } else {
        count = 0;
      }
    }

    return maxOnes;
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

    cout << sol.findMaxConsecutiveOnes(nums) << "\n";
  }

  return 0;
}