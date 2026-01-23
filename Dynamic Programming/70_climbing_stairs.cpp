#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int solve(int n) {
    if (n < 0) return 0;

    if (n == 0) return 1;

    int one_step = solve(n - 1);
    int two_step = solve(n - 2);

    return one_step + two_step;
  }

  int climbStairs(int n) {
    return solve(n);
  }
};

class Solution2 {
public:
  int t[46];

  int solve(int n) {
    if (n == 0 || n == 1 || n == 2) return n;

    if (t[n] != -1) return t[n];

    int one_step = solve(n - 1);
    int two_step = solve(n - 2);

    return t[n] = one_step + two_step;
  }

  int climbStairs(int n) {
    memset(t, -1, sizeof(t));
    return solve(n);
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

    cout << sol1.climbStairs(n) << "\n";
    cout << sol2.climbStairs(n) << "\n";
  }

  return 0;
}