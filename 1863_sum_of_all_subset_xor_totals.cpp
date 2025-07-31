#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int n = nums.size();
    int result = 0;

    for (const auto &num : nums) {
      result |= num;
    }
    return result << (n - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {3, 4, 5, 6, 7, 8};

  cout << sol.subsetXORSum(nums) << endl;

  return 0;
}