#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int maj = NULL;

    for (int i = 0; i < n; i++) {
      if (nums[i] == maj) {
        count++;
      } else if (count == 0) {
        maj = nums[i];
        count = 1;
      } else {
        count--;
      }
    }

    return maj;
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

    cout << sol.majorityElement(nums) << "\n";
  }

  return 0;
}