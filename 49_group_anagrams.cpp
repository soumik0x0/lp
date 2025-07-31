#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (const auto& s : strs) {
      string temp = s;
      sort(temp.begin(), temp.end());
      mp[temp].push_back(s);
    }

    vector<vector<string>> result;

    for (const auto& it : mp) {
      result.push_back(it.second);
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

  while (t--) {
    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
      cin >> strs[i];
    }

    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (const auto& group : result) {
      for (const auto& word : group) {
        cout << word << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}