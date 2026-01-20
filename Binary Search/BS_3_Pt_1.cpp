#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int findFirstOccurence(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] >= target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};

class Solution2 {
public:
  int findLastOccurence(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] > target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans - 1;
  }
};

class Solution3 {
public:
  int countOccurences(vector<int>& nums, int target) {
    Solution1 sol1;
    Solution2 sol2;

    int first = sol1.findFirstOccurence(nums, target);
    int last = sol2.findLastOccurence(nums, target);

    return (last - first + 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;
  Solution3 sol3;

  int T;
  cin >> T;

  while (T--) {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol1.findFirstOccurence(nums, target) << "\n";
    cout << sol2.findLastOccurence(nums, target) << "\n";
    cout << sol3.countOccurences(nums, target) << "\n";
  }

  return 0;
}