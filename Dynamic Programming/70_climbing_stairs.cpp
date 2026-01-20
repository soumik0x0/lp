#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int solve(int idx, int n) {
    if (idx > n) {
      return 0;
    }

    if (idx == n) {
      return 1;
    }

    int take_1 = solve(idx + 1, n);
    int take_2 = solve(idx + 2, n);

    return (take_1 + take_2);
  }

  int climbingStairs(int n) {
    return solve(0, n);
  }
};

class Solution2 {
public:
  int t[46];

  int solve(int idx, int n) {
    if (idx > n) {
      return 0;
    }

    if (idx == n) {
      return 1;
    }

    if (t[idx] != -1) {
      return t[idx];
    }

    int take_1 = solve(idx + 1, n);
    int take_2 = solve(idx + 2, n);

    return t[idx] = take_1 + take_2;
  }

  int climbingStairs(int n) {
    memset(t, -1, sizeof(t));
    return solve(0, n);
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

    cout << sol1.climbingStairs(n) << "\n";
    cout << sol2.climbingStairs(n) << "\n";
  }

  return 0;
}