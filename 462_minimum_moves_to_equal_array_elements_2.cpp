#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//   int minMoves2(vector<int> &nums) {
//     sort(nums.begin(), nums.end());

//     int minMoves = 0;

//     for (const auto &num : nums) {
//       minMoves += abs(num - nums[nums.size() / 2]);
//     }
//     return minMoves;
//   }
// };

class Solution {
public:
  int minMoves2(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = nums.size() - 1;
    int minMoves = 0;

    while (i < j) {
      minMoves += nums[j] - nums[i];
      i++;
      j--;
    }
    return minMoves;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 10, 2, 9};

  cout << sol.minMoves2(nums) << endl;

  return 0;
}