#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  [[nodiscard]] inline vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for (int i = 1; i < n; i++) {
      if (intervals[i][0] <= result.back()[1]) {
        result.back()[1] = max(result.back()[1], intervals[i][1]);
      } else {
        result.push_back(intervals[i]);
      }
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

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
      cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> result = sol.merge(intervals);

    for (const auto& interval : result) {
      cout << "[" << interval[0] << "," << interval[1] << "]" << " ";
    }
    cout << "\n";
  }

  return 0;
}