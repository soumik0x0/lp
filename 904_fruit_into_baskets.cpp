#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int l = 0;
    int r = 0;
    int maxLength = 0;

    unordered_map<int, int> mp;

    while (r < fruits.size()) {
      mp[fruits[r]]++;
      if (mp.size() > 2) {
        mp[fruits[l]]--;
        if (mp[fruits[l]] == 0) mp.erase(fruits[l]);
        l++;
      }
      if (mp.size() <= 2) {
        maxLength = max(maxLength, r - l + 1);
      }
      r++;
    }
    return maxLength;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> fruits(n);

    for (int i = 0; i < n; i++) {
      cin >> fruits[i];
    }

    cout << sol.totalFruit(fruits) << "\n";
  }

  return 0;
}