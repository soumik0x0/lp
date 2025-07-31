#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t) {
      return true;
    }
    return false;
  }
};

class Solution2 {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    vector<int> count(26, 0);

    for (const auto& ch : s) {
      count[ch - 'a']++;
    }

    for (const auto& ch : t) {
      count[ch - 'a']--;
    }

    for (const auto& it : count) {
      if (it != 0) {
        return false;
      }
    }
    return true;
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
    string s;
    string t;

    cin >> s >> t;

    cout << boolalpha << sol1.isAnagram(s, t) << "\n";
    cout << boolalpha << sol2.isAnagram(s, t) << "\n";
  }

  return 0;
}