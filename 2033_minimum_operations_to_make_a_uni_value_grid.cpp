#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    vector<int> values;

    for (const auto &row : grid) {
      for (const auto &val : row) {
        values.push_back(val);
      }
    }

    sort(values.begin(), values.end());

    int median = values[values.size() / 2];
    int minOps = 0;

    for (const auto &val : values) {
      if ((val - values[0]) % 2 != 0) {
        return -1;
      }
    }

    for (const auto &val : values) {
      minOps += abs(val - median) / x;
    }

    return minOps;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<vector<int>> grid = {{2, 4}, {6, 8}};

  int x = 2;

  cout << sol.minOperations(grid, x) << endl;

  return 0;
}