#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int unequalTriplets(vector<int> &nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i <= n - 3; i++) {
      for (int j = i + 1; j <= n - 2; j++) {
        if (nums[i] != nums[j]) {
          for (int k = j + 1; k <= n - 1; k++) {
            if (nums[j] != nums[k] && nums[i] != nums[k]) {
              count++;
            }
          }
        }
      }
    }
    return count;
  }
};

class Solution2 {
public:
  int unequalTriplets(vector<int> &nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) {
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

  Solution1 sol1;
  Solution2 sol2;

  vector<int> nums = {4, 4, 2, 4, 3};

  cout << sol1.unequalTriplets(nums) << endl;
  cout << sol2.unequalTriplets(nums) << endl;

  return 0;
}