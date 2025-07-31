#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();

    int flips = 0;

    int flipCountFromPastFori = 0;

    vector<bool> isFlipped(n, false);

    for(size_t i = 0; i < n; i++) {
      if(i >= k && isFlipped[i - k] == true) {
        flipCountFromPastFori--;
      }

      if(flipCountFromPastFori % 2 == nums[i]) {
        if(i + k > n) return -1;

        flipCountFromPastFori++;
        flips++;
        isFlipped[i] = true;
      }
    }
    return flips;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int k;
  cin >> k;

  vector<int> nums(n);

  for(size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution sol;

  cout << sol.minKBitFlips(nums, k) << endl;

  return 0;
}