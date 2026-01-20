#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
private:
  int solve(int idx, vector<int>& nums) {
    if (idx >= nums.size()) {
      return 0;
    }

    //steal
    int take = nums[idx] + solve(idx + 2, nums);
    //not steal
    int skip = solve(idx + 1, nums);

    return max(take, skip);
  }

public:
  int rob(vector<int>& nums) {
    return solve(0, nums);
  }
};

class Solution2 {
private:
  int t[101];
  int solve(int idx, vector<int>& nums) {
    if (idx >= nums.size()) {
      return 0;
    }

    if (t[idx] != -1) {
      return t[idx];
    }

    //steal
    int take = nums[idx] + solve(idx + 2, nums);
    //not steal
    int skip = solve(idx + 1, nums);

    return t[idx] = max(take, skip);
  }

public:
  int rob(vector<int>& nums) {
    memset(t, -1, sizeof(t));
    return solve(0, nums);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol1.rob(nums) << "\n";
    cout << sol2.rob(nums) << "\n";
  }

  return 0;
}