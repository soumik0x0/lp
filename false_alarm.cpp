#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
  int n, x;
  cin >> n >> x;

  int left = INT_MAX;
  int right = INT_MIN;

  for (int i = 0; i < n; i++) {
    int door;
    cin >> door;

    if (door == 1) {
      left = min(left, i);
      right = max(right, i);
    }
  }

  cout << (x >= right - left + 1 ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}