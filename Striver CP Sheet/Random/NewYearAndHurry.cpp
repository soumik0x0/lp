#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int totalTimeToSolve = 0;
  int count = 0;

  for (int i = 1; i <= n; i++) {
    totalTimeToSolve += 5*i;
    if ((totalTimeToSolve + k) <= 240) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}