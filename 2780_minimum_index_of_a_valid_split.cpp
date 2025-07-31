#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumIndex(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    
    for (const auto &num : nums) {
      mp2[num]++;
    }

    for (size_t i = 0; i < n; i++) {
      int num = nums[i];

      mp1[num]++;
      mp2[num]--;

      int n1 = i + 1;
      int n2 = n - i - 1;

      if (mp1[num] > n1 / 2 && mp2[num] > n2 / 2) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 2, 2, 2};

  cout << sol.minimumIndex(nums) << endl;

  return 0;
}