#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  char processStr(string s, long long k) {
    long long len = 0;

    for (const auto& ch : s) {
      if (islower(ch)) len++;
      else if (ch == '*' && len > 0) len--;
      else if (ch == '#') len *= 2;
    }

    if (k >= len) return '.';

    for (int i = (int)s.size() - 1; i >= 0; i--) {
      char ch = s[i];

      if (islower(ch)) {
        if (k == len - 1) return ch;
        len--;
      }
      else if (ch == '*') len++;
      else if (ch == '#') {
        len /= 2;
        if (k >= len) k -= len;
      }
      else if (ch == '%') {
        k = len - 1 - k;
      }
    }

    return '.';
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  cin.ignore(); // clear newline after t

  Solution sol;

  while (t--) {
    string line;
    getline(cin, line);
    if (line.empty()) {
      // If empty line, keep reading until non-empty or EOF
      while (line.empty() && getline(cin, line));
      if (line.empty()) break; // EOF
    }

    stringstream ss(line);
    string s;
    long long k;

    ss >> s >> k;

    cout << sol.processStr(s, k) << "\n";
  }

  return 0;
}
