#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int arrayPairSum(vector<int> &nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i += 2) {
      ans += nums[i];
    }
    return ans;
  }
};

class Solution2 {
public:
  int arrayPairSum(vector<int> &nums) {
    int ans;
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++) {
      if (i % 2 == 0) {
        ans += nums[i];
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol;
  Solution2 sol2;

  vector<int> nums = {6, 2, 6, 5, 1, 2};

  cout << sol.arrayPairSum(nums) << endl;
  cout << sol.arrayPairSum(nums) << endl;

  return 0;
}