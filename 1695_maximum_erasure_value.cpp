#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> seen;

    int left = 0;
    int currSum = 0;
    int maxSum = 0;

    for (int right = 0; right < n; right++) {
      while (seen.find(nums[right]) != seen.end()) {
        currSum -= nums[left];
        seen.erase(nums[left]);
        left++;
      }
      currSum += nums[right];
      seen.insert(nums[right]);
      maxSum = max(currSum, maxSum);
    }

    return maxSum;
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

    cout << sol.maximumUniqueSubarray(nums) << "\n";
  }

  return 0;
}