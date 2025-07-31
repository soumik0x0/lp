#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumSum(vector<int> &nums) {
    int n = nums.size();
    int ans = INT_MAX;

    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        for (size_t k = j + 1; k < n; k++) {
          if (nums[i] < nums[j] && nums[k] < nums[j]) {
            ans = min(ans, nums[i] + nums[j] + nums[k]);
          }
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {8, 6, 1, 5, 3};

  cout << sol.minimumSum(nums) << endl;

  return 0;
}