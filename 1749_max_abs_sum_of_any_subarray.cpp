#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int currSubArraySum = nums[0];
    int maxSubArraySum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      currSubArraySum = max(nums[i], currSubArraySum + nums[i]);
      maxSubArraySum = max(maxSubArraySum, currSubArraySum);
    }

    currSubArraySum = 0;
    int minSubArraySum = 0;
    for (int i = 1; i < nums.size(); i++) {
      currSubArraySum = min(nums[i], currSubArraySum + nums[i]);
      minSubArraySum = min(minSubArraySum, currSubArraySum);
    }

    return max(maxSubArraySum, abs(minSubArraySum));
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

    cout << sol.maxAbsoluteSum(nums) << "\n";
  }

  return 0;
}