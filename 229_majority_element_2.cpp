#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElements(vector<int>& nums) {
    int n = nums.size();
    int count1 = 0;
    int maj1 = 0;
    int count2 = 0;
    int maj2 = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == maj1) {
        count1++;
      } else if (nums[i] == maj2) {
        count2++;
      } else if (count1 == 0) {
        maj1 = nums[i];
        count1 = 0;
      } else if (count2 == 0) {
        maj2 = nums[i];
        count2 = 0;
      } else {
        count1--;
        count2--;
      }
    }

    vector<int> result;
    int freq1 = 0;
    int freq2 = 0;

    for (const auto& num : nums) {
      if (num == maj1) freq1++;
      else if (freq2 == maj2) freq2++;
    }

    if (freq1 > n / 3) result.push_back(maj1);
    if (freq2 > n / 3) result.push_back(maj2);

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    vector<int> result = sol.majorityElements(nums);

    for (const auto& it : result) {
      cout << it << " ";
    }
    cout << "\n";
  }

  return 0;
}