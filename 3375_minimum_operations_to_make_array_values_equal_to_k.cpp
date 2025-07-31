#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_set<int> st;

    for (size_t i = 0; i < n; i++) {
      if (nums[i] < k) {
        return -1;
      } else if (nums[i] > k) {
        st.insert(nums[i]);
      }
    }
    return st.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {5, 2, 5, 4, 5};
  int k = 2;

  cout << sol.minimumOperations(nums, k) << endl;

  return 0;
}