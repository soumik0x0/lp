#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findValueOfPartition(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;

    for (size_t i = 0; i < nums.size() - 1; i++) {
      ans = min(ans,  abs(nums[i] - nums[i + 1]));
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {100, 1, 10};

  cout << sol.findValueOfPartition(nums) << endl;

  return 0;
}