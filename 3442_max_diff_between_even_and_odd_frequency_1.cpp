#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int maxDifference(string s) {
    int n = s.length();

    vector<int> freq(26, 0);

    for (const auto& ch : s) {
      freq[ch - 'a']++;
    }

    int maxOdd = 0;
    int minEven = n + 1;

    for (int i = 0; i < 26; i++) {
      if (freq[i] == 0) continue;

      if (freq[i] % 2 == 0) {
        minEven = min(minEven, freq[i]);
      } else {
        maxOdd = max(maxOdd, freq[i]);
      }
    }
    return maxOdd - minEven;
  }
};

class Solution2 {
public:
  int maxDifference(string s) {
    int n = s.length();

    unordered_map<char, int> mp;

    for (const auto& ch : s) {
      mp[ch]++;
    }

    int maxOdd = 0;
    int minEven = n + 1;

    for (const auto& i : mp) {
      if (i.second % 2 == 0) {
        minEven = min(minEven, i.second);
      } else {
        maxOdd = max(maxOdd, i.second);
      }
    }
    return maxOdd - minEven;
  }
};

class Solution3 {
public:
  int maxDifference(string s) {
    int n = s.length();

    unordered_map<char, int> mp(26);

    for (const auto& ch : s) {
      mp[ch]++;
    }

    int minEven = n + 1;
    int maxOdd = 0;

    for (const auto& i : mp) {
      if (i.second % 2 == 0) {
        minEven = min(minEven, i.second);
      } else {
        maxOdd = max(maxOdd, i.second);
      }
    }
    return maxOdd - minEven;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;
  Solution3 sol3;

  int t;
  cin >> t;

  while(t--) {
    string s;
    cin >> s;

    cout << sol1.maxDifference(s) << endl;
    cout << sol2.maxDifference(s) << endl;
    cout << sol3.maxDifference(s) << endl;
  }

  return 0;
}