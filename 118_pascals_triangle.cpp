#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  vector<vector<int>> generate(const int numRows) {
    vector<vector<int>> result;
    for (int i = 0; i < numRows; i++) {
      result.push_back(vector<int>(i + 1, 1));
      for (int j = 1; j < i; j++) {
        result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
      }
    }
    return result;
  }
};

class Solution2 {
public:
  vector<vector<int>> generate(const int numRows) {
    vector<vector<int>> result;
    for (int i = 0; i < numRows; i++) {
      result.emplace_back(i + 1, 1);
      for (int j = 1; j < i; j++) {
        result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
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
    int n;
    cin >> n;

    vector<vector<int>> triangle1 = sol1.generate(n);
    vector<vector<int>> triangle2 = sol2.generate(n);

    for (const auto& row : triangle1) {
      for (const auto& it : row) {
        cout << it << " ";
      }
      cout << "\n";
    }

    for (const auto& row : triangle2) {
      for (const auto& it : row) {
        cout << it << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}