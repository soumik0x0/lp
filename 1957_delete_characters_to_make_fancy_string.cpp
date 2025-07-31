#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string makeFancyString(string s) {
    int n = s.length();

    string result = "";

    result.push_back(s[0]);
    int freq = 1;

    for (int i = 1; i < n; i++) {
      if (s[i] == result.back()) {
        freq++;
        if (freq < 3) {
          result.push_back(s[i]);
        }
      } else {
        result.push_back(s[i]);
        freq = 1;
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

  int T;
  cin >> T;
  cin.ignore();

  while (T--) {
    string s;
    getline(cin, s);

    cout << sol.makeFancyString(s) << "\n";
  }

  return 0;
}