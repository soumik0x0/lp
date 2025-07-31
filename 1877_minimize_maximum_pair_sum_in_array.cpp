#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    int j = n - 1;

    for (size_t i = 0; i < n; i++) {
      ans = max(ans, nums[i] + nums[j]);
      j--;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {3, 5, 4, 2, 4, 6};

  cout << sol.minPairSum(nums) << endl;

  return 0;
}