#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int m;
  int n;

  bool solve(string& s, string& t, int i, int j) {
    if (i == m) return true;

    if (j == n) return false;

    if (s[i] == t[j]) {
      return solve(s, t, i + 1, j + 1);
    } else {
      return solve(s, t, i, j + 1);
    }
  }

  bool isSubsequence(string& s, string& t) {
    m = s.length();
    n = t.length();

    return solve(s, t, 0, 0);
  }
};

class Solution2 {
public:
  int m;
  int n;
  vector<vector<int>> dp;

  bool solve(string& s, string& t, int i, int j) {
    if (i == m) return true;

    if (j == n) return false;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
      return dp[i][j] = solve(s, t, i + 1, j + 1);
    } else {
      return dp[i][j] = solve(s, t, i, j + 1);
    }
  }

  bool isSubsequence(string& s, string& t) {
    m = s.length();
    n = t.length();

    dp.resize(m + 1, vector<int>(n + 1, -1));

    return solve(s, t, 0, 0);
  }
};

class Solution3 {
public:
  bool isSubsequence(string& s, string& t) {
    int m = s.length();
    int n = t.length();

    int i = 0;
    int j = 0;

    while (i < m && j < n) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }

    return (i == m);
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
    string s, t;
    cin >> s >> t;

    cout << boolalpha << sol1.isSubsequence(s, t) << "\n";
    cout << boolalpha << sol2.isSubsequence(s, t) << "\n";
    cout << boolalpha << sol3.isSubsequence(s, t) << "\n";
  }

  return 0;
}