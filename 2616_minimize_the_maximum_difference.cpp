#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(vector<int>& nums, int mid, int p) {
    int n = nums.size();
    int i = 0;
    int countPairs = 0;

    while(i < n - 1) {
      if (nums[i + 1] - nums[i] <= mid) {
        countPairs++;
        i += 2;
      } else {
        i++;
      }
    }
    return countPairs >= p;
  }

  int minimizeMax(vector<int>& nums, int p) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums[n - 1] - nums[0];
    int result = INT_MAX;

    while(l <= r) {
      int mid = l + (r - l)/2;

      if (isValid(nums, mid, p)) {
        result = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while(t--) {
    int n, p;
    cin >> n >> p;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol.minimizeMax(nums, p) << endl;
  }

  return 0;
}