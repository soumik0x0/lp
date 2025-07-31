#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  char kthCharacter(int k) {
    string s = "a";

    while (s.length() < k) {
      string t = "";

      for (int i = 0; i < s.length(); i++) {
        t += (s[i] + 1);
      }

      s += t;
    }

    return s[k - 1];
  }
};

class Solution2 {
public:
  char kthCharacter(int k) {
    int x = __builtin_popcount(k - 1); //counts the no. of set bits in binary representation of (k - 1)

    return 'a' + x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;

    cout << sol1.kthCharacter(k) << "\n";
    cout << sol2.kthCharacter(k) << "\n"; 
  }

  return 0;
}