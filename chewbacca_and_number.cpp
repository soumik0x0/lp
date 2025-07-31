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
  cin.ignore();

  while (T--) {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
      int d = s[i] - '0';
      int inverted = 9 - d;

      if (i == 0 && d == 9) continue;
      if (inverted < d) {
        s[i] = inverted + '0';
      }
    }

    cout << s << "\n";
  }
  return 0;
}