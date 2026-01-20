#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0;
        for (int num : nums) {
            totalXOR ^= num;
        }

        if (totalXOR != 0) {
            return nums.size();
        }

        for (int num : nums) {
            if (num != 0) {
                return nums.size() - 1;
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

    cout << sol.longestSubsequence(nums) << "\n";
  }

  return 0;
}