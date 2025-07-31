#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPairs(vector<int> &nums, int target) {
    int n = nums.size();
    int count = 0;

    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] < target) {
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

  vector<int> nums = {-1, 1, 2, 3, 1};
  int target = 2;

  cout << sol.countPairs(nums, target) << endl;

  return 0;
}