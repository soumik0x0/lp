#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool isVowel(char ch) {
    char c = tolower(ch);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      return true;
    }

    return false;
  }

public:
  string reverseVowels(string s) {
    int start = 0;
    int end = s.length() - 1;

    while (start <= end) {
      if (!isVowel(s[start])) {
        start++;
      }
      else if (!isVowel(s[end])) {
        end--;
      }
      else swap(s[start++], s[end--]);
    }

    return s;
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

    cout << sol.reverseVowels(s) << "\n";
  }

  return 0;
}