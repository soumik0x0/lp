#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> temp = matrix;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          for (int k = 0; k < m; k++) {
            temp[k][j] = 0;
          }

          for (int k = 0; k < n; k++) {
            temp[i][k] = 0;
          }
        }
      }
    }

    matrix = temp;
  }
};

class Solution2 {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          row[i] = 0;
          col[j] = 0;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (row[i] == 0 || col[j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

class Solution3 {
public:
  void setZeroes(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool isFirstRowZero = false;
    bool isFirstColZero = false;

    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        isFirstColZero = true;
      }
    }

    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        isFirstRowZero = true;
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (isFirstRowZero) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }

    if (isFirstColZero) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
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
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }

    sol1.setZeroes(matrix);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}