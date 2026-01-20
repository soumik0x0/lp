#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    map<int, vector<int>> mp;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mp[i - j].push_back(mat[i][j]);
      }
    }

    for (auto& it : mp) {
      sort(it.second.begin(), it.second.end());
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        mat[i][j] = mp[i - j].back();
        mp[i - j].pop_back();
      }
    }

    return mat;
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

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
      }
    }

    vector<vector<int>> result = sol.diagonalSort(mat);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << result[i][j] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}