#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int MOD = 1e9 + 7;
  int solve(int n, int num, int x) {
    if (n == 0) {
      return 1;
    }

    if (n < 0) {
      return 0;
    }

    int currPow = pow(num, x);
    if (currPow > n) {
      return 0;
    }

    int take = solve(n - currPow, num + 1, x);
    int skip = solve(n, num + 1, x);

    return (take + skip) % MOD;
  }

  int numberOfWays(int n, int x) {
    return solve(n, 1, x);
  }
};

class Solution2 {
public:
  int MOD = 1e9 + 7;
  int t[301][301];

  int solve(int n, int num, int x) {
    if (n == 0) {
      return 1;
    }

    if (n < 0) {
      return 0;
    }

    int currPow = pow(num, x);
    if (currPow > n) {
      return 0;
    }

    if (t[n][num] != -1) {
      return t[n][num];
    }

    int take = solve(n - currPow, num + 1, x);
    int skip = solve(n, num + 1, x);

    return t[n][num] = (take + skip) % MOD;
  }

  int numberOfWays(int n, int x) {
    memset(t, -1, sizeof(t));
    return solve(n, 1, x);
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
    int n, x;
    cin >> n >> x;

    cout << sol1.numberOfWays(n, x) << "\n";
    cout << sol2.numberOfWays(n, x) << "\n";
  }

  return 0;
}