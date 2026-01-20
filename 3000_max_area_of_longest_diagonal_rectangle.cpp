#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int n = dimensions.size();

    int maxArea = 0;
    int maxDiag = 0;

    for (int i = 0; i < n; i++) {
      int l = dimensions[i][0];
      int w = dimensions[i][1];

      int diag = l*l + w*w;
      int area = l*w;

      if (diag > maxDiag) {
        maxDiag = diag;
        maxArea = area;
      } else if (diag == maxDiag) {
        maxArea = max(area, maxArea);
      }
    }

    return maxArea;
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

    vector<vector<int>> dimensions(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
      cin >> dimensions[i][0] >> dimensions[i][1];
    }

    cout << sol.areaOfMaxDiagonal(dimensions) << "\n";
  }

  return 0;
}