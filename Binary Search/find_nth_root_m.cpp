#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nthRoot(int n, int m) {
    int low = 1;
    int high = m;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int midN = pow(mid, n);

      if (midN == m) return mid;
      else if (midN < m) low = mid + 1;
      else high = mid - 1;
    }

    return -1;
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
    int n, m;
    cin >> n >> m;

    cout << sol.nthRoot(n, m) << "\n";
  }

  return 0;
}