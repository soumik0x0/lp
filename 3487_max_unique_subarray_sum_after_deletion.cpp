#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int maxSum(vector<int>& nums) {
    unordered_set<int> positiveNumSet;

    for (const auto& num : nums) {
      if (num > 0) {
        positiveNumSet.emplace(num);
      }
    }

    if (positiveNumSet.empty()) {
      return *max_element(nums.begin(), nums.end());
    }

    return accumulate(positiveNumSet.begin(), positiveNumSet.end(), 0);
  }
};

class Solution2 {
public:
  int maxSum(vector<int>& nums) {
    unordered_map<int, int> freq;

    int maxVal = *max_element(nums.begin(), nums.end());
    if (maxVal < 0) return maxVal;

    for (const auto& it : nums) {
      freq[it]++;
    }

    int sum = 0;

    for (const auto& pair : freq) {
      if (pair.first >= 0) {
        sum += pair.first;
      }
    }

    return sum;
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

    cout << sol1.maxSum(nums) << "\n";
    cout << sol2.maxSum(nums) << "\n";
  }
 
  return 0;
}