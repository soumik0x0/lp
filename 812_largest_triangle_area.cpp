#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    double maxArea = 0.0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          double x1 = points[i][0];
          double y1 = points[i][1];

          double x2 = points[j][0];
          double y2 = points[j][1];

          double x3 = points[k][0];
          double y3 = points[k][1];

          double shoeLace = 0.5 * abs(x1 * (y2 - y3) + x2 * (y1 - y3) + x3 * (y1 - y2));

          maxArea = max(maxArea, shoeLace);
        }
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

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
      cin >> points[i][0] >> points[i][1];
    }

    cout << sol.largestTriangleArea(points) << "\n";
  }

  return 0;
}