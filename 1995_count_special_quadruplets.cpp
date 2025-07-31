#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int n = nums.size();
    int count = 0;

    for (int a = 0; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        for (int c = b + 1; c < n; c++) {
          for (int d = c + 1; d < n; d++) {
            if (nums[a] + nums[b] + nums[c] == nums[d]) {
              count++;
            }
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

  vector<int> nums = {1, 1, 1, 3, 5};

  cout << sol.countQuadruplets(nums) << endl;

  return 0;
}