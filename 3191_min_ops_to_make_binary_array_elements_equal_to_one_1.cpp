#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for(size_t i = 0; i < n - 2; i++) {
      if(nums[i] == 0) {
        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        count++;
      }
    }
    return (nums[n - 2] == 1 && nums[n - 1] == 1) ? count : -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int n;
  cin >> n;

  vector<int> nums(n);

  for(size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << sol.minOperations(nums) << endl;

  return 0;
}