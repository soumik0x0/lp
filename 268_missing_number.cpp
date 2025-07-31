#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = n;

    for (int i = 0; i < n; i++) {
      ans ^= i;
      ans ^= nums[i];
    }

    return ans;
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

    cout << sol.missingNumber(nums) << "\n";
  }

  return 0;
}