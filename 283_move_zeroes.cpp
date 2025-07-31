#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    for (int right = 0; right < n; right++) {
      if (nums[right] != 0) {
        swap(nums[left], nums[right]);
        left++;
      }
    }
  }
};

class Solution2 {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int insertPosition = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        nums[insertPosition] = nums[i];
        insertPosition++;
      }
    }

    while (insertPosition < n) {
      nums[insertPosition++] = 0;
    }
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

    vector<int> nums1 = nums;
    sol1.moveZeroes(nums1);
    for (const auto& it : nums1) {
      cout << it << " ";
    }
    cout << "\n";

    sol2.moveZeroes(nums1);
    for (const auto& it : nums1) {
      cout << it << " ";
    }
    cout << "\n";
  }

  return 0;
}