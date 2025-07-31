#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    if (k == 0) {
      for (int i = 0; i < n - 1; i++) {
        if (nums[i] == 0 && nums[i + 1] == 0) {
          return true;
        }
      }
      return false;
    }

    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = -1;  // We add this to handle cases where subarrays start from index 0

    for (int i = 0; i < n; i++) {
      sum += nums[i];
      int remainder = sum % k;

      //if (remainder < 0) remainder += k;  // Ensure positive remainders

      if (mp.find(remainder) != mp.end()) {
        if (i - mp[remainder] >= 2) {
          return true;
        }
      } else {
        mp[remainder] = i;  // Only store the first occurrence of each remainder
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << boolalpha << sol.checkSubarraySum(nums, k) << endl;
  }

  return 0;
}
