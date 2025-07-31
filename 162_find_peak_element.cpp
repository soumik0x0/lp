#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPeak(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low) / 2;

    while (low < high) {
      if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
        return mid;
      }
      else if (nums[mid - 1] > nums[mid]) {
        high = mid + 1;
      } else {
        low = mid + 1;
      }
      if (mid == 0) {
        if (nums[0] > nums[1]) {
          return 0;
        } else {
          return 1;
        }
        if (mid == nums.size() - 1) {
          if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
          } else {
            return nums.size() - 2;
          }
        }
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 2, 3, 1};

  cout << sol.findPeak(nums) << endl;

  return 0;
}