#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> buildArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
      ans.push_back(nums[nums[i]]);
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {0, 2, 1, 5, 3, 4};

  vector<int> result = sol.buildArray(nums);

  for (const auto &num : result) {
    cout << num << " ";
  }

  cout << endl;

  return 0;
}