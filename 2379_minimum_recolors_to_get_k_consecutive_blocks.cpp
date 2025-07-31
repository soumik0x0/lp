#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int n = blocks.size();

    int W = count(blocks.begin(), blocks.begin() + k, 'W');

    int reColors = W;

    for (int left = 0, right = k; right < n; left++, right++) {
      W += (blocks[right] == 'W') - (blocks[left] == 'W');
      reColors = min(W, reColors); 
    }

    return reColors;
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

    string blocks;

    cin.ignore();

    getline(cin, blocks);

    cout << sol.minimumRecolors(blocks, k) << "\n";
  }

  return 0;
}