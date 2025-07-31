#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int firstUniqChar(string &s) {
    unordered_map<char, int> mp;

    for (char c : s) {
      mp[c]++;
    }

    for (int i = 0; i < s.length(); i++) {
      if (mp[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};

class Solution2 {
public:
  int firstUniqChar(string &s) {
    int cnt[26] = {0};

    for (char c : s) {
      cnt[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
      if (cnt[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s = "leetcode";

  Solution1 sol1;
  Solution2 sol2;

  cout << sol1.firstUniqChar(s) << endl;
  cout << sol2.firstUniqChar(s) << endl;

  return 0;
}