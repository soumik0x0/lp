#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (size_t i = 1; i < n; i++) {
      if (intervals[i][0] < result.back()[1]) {
        result.back()[1] = max(result.back()[1], intervals[i][1]);
      } else {
        result.push_back(intervals[i]);
      }
    }
    return result;
  }

  bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
    vector<vector<int>> horizontal;
    vector<vector<int>> vertical;

    for (const auto &coord : rectangles) {
      int x1 = coord[0];
      int y1 = coord[1];
      int x2 = coord[2];
      int y2 = coord[3];

      horizontal.push_back({x1, x2});
      vertical.push_back({y1, y2});
    }

    vector<vector<int>> result1 = merge(horizontal);
    vector<vector<int>> result2 = merge(vertical);

    if (result1.size() >= 3) return true;

    return result2.size() >= 3;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<vector<int>> rectangles = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
  int n = 5;

  cout << boolalpha << sol.checkValidCuts(n, rectangles) << endl;

  return 0;
}