#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    for (size_t i = 0; i < n; i++) {
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

  vector<int> nums = {4, 1, 2, 1, 2};

  cout << sol.singleNumber(nums) << endl;

  return 0;
}