#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int n = nums.size();
    int window_sum = 0;
    int result = 0;
    int count_zeroes = 0;

    int i = 0;
    int j = 0;

    while (j < n) {
      window_sum += nums[j];

      while (i < j && (window_sum > goal || nums[i] == 0)) {
        if (nums[i] == 0) {
          count_zeroes++;
        } else {
          count_zeroes = 0;
        }

        window_sum -= nums[i];
        i++;
      }
      if (window_sum == goal) {
        result += 1 + count_zeroes;
      }
      j++;
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;

  cout << sol.numSubarraysWithSum(nums, goal) << endl;

  return 0;
}