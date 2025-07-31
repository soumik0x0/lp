#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int n = s.size();
    int m = g.size();

    int contentChildren = 0;
    int cookieIdx     = 0;

    while (cookieIdx < n && contentChildren < m) {
      if (s[cookieIdx] >= g[contentChildren]) {
        contentChildren++;
      }
      cookieIdx++;
    }

    return contentChildren;
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
    int n, m;
    cin >> n >> m;

    vector<int> g(n);
    vector<int> s(m);

    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> s[i];
    }

    cout << sol.findContentChildren(g, s) << "\n";
  }

  return 0;
}