#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistance(vector<int>& colors) {
    int n = colors.size();

    int maxDistance1 = INT_MIN;
    int maxDistance2 = INT_MIN;

    int k = 1;

    while(k < n) {
      if (colors[0] != colors[k]) maxDistance1 = max(maxDistance1, k);
      if (colors[k] != colors[n - 1]) maxDistance2 = max(maxDistance2, n - 1 - k);
      k++;
    }
    return max(maxDistance1, maxDistance2);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while(t--) {
    int n;
    cin >> n;

    vector<int> colors(n);

    for (int i = 0; i < n; i++) {
      cin >> colors[i];
    }

    cout << sol.maxDistance(colors) << endl;
  }

  return 0;
}