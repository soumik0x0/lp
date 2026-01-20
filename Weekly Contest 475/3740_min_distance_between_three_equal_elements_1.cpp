#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumDistance(vector<int>& nums) {
    if (nums.size() < 3) return -1;

    int ans = INT_MAX;

    for (int i = 0; i < nums.size() - 2; i++) {
      for (int j = i + 1; j < nums.size() - 1; j++) {
        if (nums[j] != nums[i]) continue;
        for (int k = j + 1; k < nums.size(); k++) {
          if (nums[j] == nums[k]) {
            ans = min(ans, (j - i) + (k - j) + (k - i));
          }
        }
      }
    }

    if (ans == INT_MAX) return -1;
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

    cout << sol.minimumDistance(nums) << "\n";
  }

  return 0;
}