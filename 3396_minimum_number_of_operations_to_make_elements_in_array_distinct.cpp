#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> st;

    for (int i = n - 1; i >= 0; i--) {
      if (st.count(nums[i])) {
        return ceil((i + 1)/3.0);
      }
      st.insert(nums[i]);
    }
    return 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};

  cout << sol.minimumOperations(nums) << endl;

  return 0;
}