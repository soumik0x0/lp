#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string processStr(string s) {
    string result;

    for (const auto& ch : s) {
      if ('a' <= ch && ch <= 'z') {
        result += ch;
      }
      else if (ch == '*') {
        if (!result.empty()) {
          result.pop_back();
        }
      }
      else if (ch == '#') {
        result += result;
      }
      else if (ch == '%') {
        reverse(result.begin(), result.end());
      }
    }

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    string s;

    getline(cin, s);

    cout << sol.processStr(s) << "\n";
  }

  return 0;
}