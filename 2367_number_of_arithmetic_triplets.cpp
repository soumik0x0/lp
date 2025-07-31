#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    int n = nums.size();
    int count = 0;

    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        for (size_t k = j + 1; k < n; k++) {
          if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
            count++;
          }
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

  vector<int> nums = {0, 1, 4, 6, 7, 10};
  int diff = 3;

  cout << sol.arithmeticTriplets(nums, diff) << endl;

  return 0;
}