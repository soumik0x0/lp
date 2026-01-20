#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i + 1] + nums[i + 2] > nums[i]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }

    return 0;
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

    cout << sol.largestPerimeter(nums) << "\n";
  }

  return 0;
}