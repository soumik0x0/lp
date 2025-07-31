#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    int i = 0, j = 1;

    while (j < n) {
      if (nums[i] != nums[j]) {
        i++;
        nums[i] = nums[j];
      }
      j++;
    }

    return i + 1;
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

    cout << sol.removeDuplicates(nums) << "\n";
  }

  return 0;
}