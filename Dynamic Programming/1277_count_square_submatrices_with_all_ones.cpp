#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int m, n;

  int solve(int i, int j, vector<vector<int>>& matrix) {
    if (i >= m || j >= n) {
      return 0;
    }

    if (matrix[i][j] == 0) {
      return 0;
    }

    int right = solve(i, j + 1, matrix);
    int down = solve(i + 1, j, matrix);
    int diagonal = solve(i + 1, j + 1, matrix);

    return 1 + min({right, down, diagonal});
  }

  int countSquares(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          result += solve(i, j, matrix);
        }
      }
    }

    return result;
  }
};

class Solution2 {
public:
  int m, n;
  vector<vector<int>> t;

  int solve(int i, int j, vector<vector<int>>& matrix) {
    if (i >= m || j >= n) {
      return 0;
    }

    if (matrix[i][j] == 0) {
      return 0;
    }

    if (t[i][j] != -1) {
      return t[i][j];
    }

    int right = solve(i, j + 1, matrix);
    int down = solve(i + 1, j, matrix);
    int diagonal = solve(i + 1, j + 1, matrix);

    return t[i][j] = 1 + min({right, diagonal, down});
  }

  int countSquares(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    t.resize(m, vector<int>(n, -1));

    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          result += solve(i, j, matrix);
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

  int T;
  cin >> T;

  while (T--) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }

    cout << sol1.countSquares(matrix) << "\n";
    cout << sol2.countSquares(matrix) << "\n";
  }

  return 0;
}