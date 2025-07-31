#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> addPermutations(int n, int k) {
    vector<int> P;

    for (int i = 0; i < n; i++) {
      P.push_back(i + 1);
    }

    reverse(P.begin() + k - 1, P.end());

    return P;
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
    int n, k;
    cin >> n >> k;

    vector<int> result = sol.addPermutations(n, k);

    for (const auto& it : result) {
      cout << it << " ";
    }
    cout << "\n";
  }

  return 0;
}