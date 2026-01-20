#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> result;

    map<int, vector<int>> mp;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mp[i + j].push_back(mat[i][j]);
      }
    }

    bool flip = true;
    for (auto& it : mp) {
      if (flip) {
        reverse(it.second.begin(), it.second.end());
      }

      for (auto& num : it.second) {
        result.push_back(num);
      }

      flip = !flip;
    }

    return result;
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

    vector<int> result = sol.findDiagonalOrder(mat);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}