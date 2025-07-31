#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(vector<int>& nums) {
    int n = nums.size();

    int peak = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[(i + 1) % n]) {
        peak++;
      }
    }

    return peak <= 1;
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

    cout << boolalpha << sol.check(nums) << "\n";
  }

  return 0;
}