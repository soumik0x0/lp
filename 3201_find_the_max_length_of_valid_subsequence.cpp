#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumLength(vector<int>& nums) {
    int n = nums.size();

    int countEven = 0;
    int countOdd = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] % 2 == 0) {
        countEven++;
      } else {
        countOdd++;
      }
    }

    int parity = nums[0] % 2;
    int countAlternating = 1;

    for (int i = 1; i < n; i++) {
      int currParity = nums[i] % 2;
      if (currParity != parity) {
        countAlternating++;
        parity = currParity;
      }
    }

    return max({countEven, countOdd, countAlternating});
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

    cout << sol.maximumLength(nums) << "\n";
  }

  return 0;
}