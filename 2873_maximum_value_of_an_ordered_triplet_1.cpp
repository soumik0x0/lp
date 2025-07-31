#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    long long n = nums.size();
    long long ans = INT_MIN;

    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + 1; j < n; j++) {
        for (size_t k = j + 1; k < n; k++) {
          ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
        }
      }
    }
    if (ans < 0) return 0;
    else return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 10, 3, 4, 19};

  cout << sol.maximumTripletValue(nums) << endl;

  return 0;
}