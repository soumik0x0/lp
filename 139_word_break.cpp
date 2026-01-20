#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  unordered_set<string> st;
  int n;

  bool solve(int idx, string& s) {
    if (idx >= n) {
      return true;
    }

    if (st.find(s) != st.end()) {
      return true;
    }

    for (int l = 1; l <= n; l++) {
      string temp = s.substr(idx, l);

      if (st.find(temp) != st.end() && solve(idx + l, s)) {
        return true;
      }
    }

    return false;
  }

  bool wordBreak(string s, vector<string> wordDict) {
    n = s.length();

    for (const auto& word : wordDict) {
      st.insert(word);
    }

    return solve(0, s);
  }
};

class Solution2 {
public:
  unordered_set<string> st;
  int n;
  int t[301];

  bool solve(int idx, string& s) {
    if (idx >= n) {
      return true;
    }

    if (t[idx] != -1) {
      return t[idx];
    }

    if (st.find(s) != st.end()) {
      return true;
    }

    for (int l = 1; l <= n; l++) {
      string temp = s.substr(idx, l);

      if (st.find(temp) != st.end() && solve(idx + l, s)) {
        return true;
      }
    }

    return false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    n = s.length();

    for (const auto& word : wordDict) {
      st.insert(word);
    }

    memset(t, -1, sizeof(t));

    return solve(0, s);
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

  while (T--) {
    int n;
    string s;
    cin >> n >> s;

    vector<string> wordDict(n);

    for (int i = 0; i < n; i++) {
      cin >> wordDict[i];
    }

    cout << boolalpha << sol1.wordBreak(s, wordDict) << "\n";
    cout << boolalpha << sol2.wordBreak(s, wordDict) << "\n";
  }

  return 0;
}