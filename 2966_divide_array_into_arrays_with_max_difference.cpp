//T.C : O(n logn)
//S.C : O(n)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int i = 0; i < n; i += 3) {
      if (nums[i + 2] - nums[i] > k) {
        return {};
      }

      result.push_back({nums[i], nums[i + 1], nums[i + 2]});
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
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    vector<vector<int>> result = sol.divideArray(nums, k);

    for (const auto& group : result) {
      for (const auto& nums : group) {
        cout << nums << " ";
      }
      cout << endl;
    }
  }

  return 0;
}