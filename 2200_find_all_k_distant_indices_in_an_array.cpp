#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();

    vector<int> result;

    for (int j = 0; j < n; j++) {
      if (nums[j] == key) {
        int start = max(0, j - k);
        int end   = min(j + k, n - 1);

        if (!result.empty() and result.back() >= start) {
          start = result.back() + 1;
        }

        for (int i = start; i <= end; i++) {
          result.push_back(i);
        }
      }
    }
    return result;
  }
};

class Solution2 {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();

    vector<int> result;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (abs(i - j) <= k and nums[j] == key) {
          result.push_back(i);
        }
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int t;
  cin >> t;

  while(t--) {
    int n;
    int key;
    int k;

    cin >> n >> key >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    vector<int> result1 = sol1.findKDistantIndices(nums, key, k);
    vector<int> result2 = sol2.findKDistantIndices(nums, key, k);

    for (const auto& i : result1) {
      cout << i << " ";
    }
    cout << endl;

    for (const auto& i : result2) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}