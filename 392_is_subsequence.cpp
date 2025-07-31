#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  bool isSubsequence(string s, string t) {
    int m = s.length();
    int n = t.length();

    int i = 0;
    int j = 0;

    while (i < m && j < n) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }

    return i == m;
  }
};

class Solution2 {
public:
  bool isSubsequence(string s, string t) {
    map<char, vector<int>> mp;

    for (int i = 0; i < t.length(); i++) {
      char ch = t[i];
      mp[ch].push_back(i);
    }

    int prev = -1;

    for (const auto& ch : s) {
      if (mp.find(ch) == mp.end())
        return false;

      vector<int> indices = mp[ch];

      auto it = upper_bound(indices.begin(), indices.end(), prev);

      if (it == indices.end())
        return false;

      prev = *it;
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

  int T;
  cin >> T;
  cin.ignore();

  while (T--) {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    cout << boolalpha << sol1.isSubsequence(s, t) << "\n";
    cout << boolalpha << sol2.isSubsequence(s, t) << "\n"; 
  }

  return 0;
}