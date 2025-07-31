#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumIncrementForUnique(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < n; i++) {
      if (nums[i] <= nums[i -])
    }
  }
};