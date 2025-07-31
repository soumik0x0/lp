#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string word) {
    if (word.length() < 3) {
      return false;
    }

    bool has_vowel = false;
    bool has_consonant = false;

    for (auto& ch : word) {
      if (isalpha(ch)) {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
          has_vowel = true;
        } else {
          has_consonant = true;
        }
      } else if (!isdigit(ch)) {
        return false;
      }
    }

    return has_vowel && has_consonant;
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
    string word;
    getline(cin, word);

    cout << boolalpha << sol.isValid(word) << "\n";
  }

  return 0;
}