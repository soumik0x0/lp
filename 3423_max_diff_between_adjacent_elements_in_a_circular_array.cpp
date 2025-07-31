#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxAdjacentDifference(vector<int>& nums) {
    int n = nums.size();

    int maxDiff = 0;

    for (int i = 0; i < n; i++) {
      maxDiff = max(maxDiff, abs(nums[i] - nums[(i + 1) % n]));
    }
    return maxDiff;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol.maxAdjacentDifference(nums) << endl;
  }

  return 0;
}