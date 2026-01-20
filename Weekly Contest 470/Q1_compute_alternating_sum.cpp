#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int alternatingSum(vector<int>& nums) {
    int n = nums.size();
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        evenSum += nums[i];
      } else {
        oddSum += nums[i];
      }
    }

    return evenSum - oddSum;
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

    cout << sol.alternatingSum(nums) << "\n";
  }

  return 0;
}