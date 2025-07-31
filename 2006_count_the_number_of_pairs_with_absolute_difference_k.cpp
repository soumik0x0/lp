#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    int count = 0;
    int n = nums.size();

    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        if (abs(nums[i] - nums[j]) == k) {
          count++;
        }
      }
    }
    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 2, 2, 1};
  int k = 1;

  cout << sol.countKDifference(nums, k) << endl;

  return 0;
}