#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

//Using only recursion
class Solution1 {
public:
  int solve(vector<vector<int>>& grid, int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1) {
      return grid[i][j];
    }

    if (i == m - 1) {
      return grid[i][j] + solve(grid, i, j + 1, m, n);
    } else if (j == n - 1) {
      return grid[i][j] + solve(grid, i + 1, j, m, n);
    } else {
      return grid[i][j] + min(solve(grid, i + 1, j, m, n), solve(grid, i, j + 1, m, n));
    }
  }

  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    return solve(grid, 0, 0, m, n);
  }
};

//Using recursion + memoization + vector
class Solution2 {
public:
  int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<>) {
    if (t[i][j] != -1) {
      return grid[i][j];
    }
  }

  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> t(m + 1, vector<int>(n - 1, -1));

    return solve(grid, 0, 0, m, n);
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
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }

    cout << sol.minPathSum(grid) << "\n";
  }

  return 0;
}