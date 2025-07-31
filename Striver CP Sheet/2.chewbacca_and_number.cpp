#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
      int t = s[i] - '0';
      int inverted = 9 - t;

      if (i == 0 && t == 9) continue;
      if (inverted < t) {
        s[i] = inverted + '0';
      }
    }

    cout << s << "\n";
  }

  return 0;
}