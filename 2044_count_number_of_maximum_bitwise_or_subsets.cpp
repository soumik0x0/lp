#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int countSubsets(int idx, int currOR, int maxOR, vector<int>& nums) {
    if (idx == nums.size()) {
      if (currOR == maxOR)
        return 1;
      return 0;
    }

    //take
    int take = countSubsets(idx + 1, currOR | nums[idx], maxOR, nums);
    //skip
    int skip = countSubsets(idx + 1, currOR, maxOR, nums);

    return (take + skip);
  }

  int countMaxOrSubsets(vector<int>& nums) {
    int maxOR = 0;

    int currOR = 0;

    for (const auto& num : nums) {
      maxOR |= num;
    }

    return countSubsets(0, currOR, maxOR, nums);
  }
};

class Solution2 {
public:
  int countSubsets(int idx, int currOR, int maxOR, vector<int>& nums, vector<vector<int>>& t) {
    if (idx == nums.size()) {
      if (currOR == maxOR)
        return t[idx][maxOR] = 1;
      return t[idx][maxOR] = 0;
    }

    if (t[idx][maxOR] != -1) {
      return t[idx][maxOR];
    }

    //take
    int take = countSubsets(idx + 1, currOR | nums[idx], maxOR, nums, t);
    //skip
    int skip = countSubsets(idx + 1, currOR, maxOR, nums, t);

    return t[idx][maxOR] = take + skip;
  }

  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    int currOR = 0;
    int maxOR = 0;

    for (const auto& num : nums) {
      maxOR |= num;
    }

    vector<vector<int>> t(n + 1, vector<int>(maxOR + 1, -1));

    return countSubsets(0, currOR, maxOR, nums, t);
  }
};

class Solution3 {
public:
  unordered_map<pair<int, int>, int> t;

  int countSubsets(int idx, int currOR, int maxOR, vector<int>& nums) {
    if (idx == nums.size()) {
      return (currOR == maxOR) ? 1 : 0;
    }

    pair<int, int> key = {idx, maxOR};
    if (t.find(key) != t.end()) {
      return t[key];
    }

    //take
    int take = countSubsets(idx + 1, currOR | nums[idx], maxOR, nums);
    //skip
    int skip = countSubsets(idx + 1, currOR, maxOR, nums);

    return t[key] = take + skip;
  }

  int countMaxOrSubsets(vector<int>& nums) {
    int maxOR = accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
    int currOR = 0;
    return countSubsets(0, currOR, maxOR, nums);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;

  int T;
  //cin >> T;
  scanf("%d", &T);

  while (T--) {
    int n;
    scanf("%d", &n);

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol1.countMaxOrSubsets(nums) << "\n";
  }

  return 0;
}