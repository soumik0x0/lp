#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();

    int mid = n / 2;

    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += mat[i][i];

      sum += mat[n - 1 - i][i];
    }

    if (n % 2 == 1) {
      sum -= mat[mid][mid];
    }

    return sum;
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>>mat (n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }

    cout << sol.diagonalSum(mat) << "\n";
  }

  return 0;
}