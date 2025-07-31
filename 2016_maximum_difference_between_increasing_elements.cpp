#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumDifference(vector<int>& nums) {
    int n = nums.size();

    int minElement = nums[0];

    int maxDiff = -1;

    for (int j = 1; j < n; j++) {
      if (nums[j] > minElement) {
        maxDiff = max(maxDiff, nums[j] - minElement);
      } else {
        minElement = nums[j];
      }
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

    cout << sol.maximumDifference(nums) << endl;
  }

  return 0;
}