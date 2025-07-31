#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    double maxAverage = INT_MIN;

    while(j < n) {
      sum += nums[j];

      if(j - i + 1 == k) {
        maxAverage = max(maxAverage, (double)sum/k);
        sum -= nums[i];
        i++;
      }
      j++;
    }
    return maxAverage;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solution sol;
  int n;
  cin >> n;
  int k;
  cin >> k;

  vector<int> nums(n); //= {1, 12, -5, -6, 50, 3};
  for(size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << sol.findMaxAverage(nums, k) << endl;
}