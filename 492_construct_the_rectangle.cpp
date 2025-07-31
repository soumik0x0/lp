#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> constructRectangle(int area) {
    int w = sqrt(area);
    while (area % w != 0) w--;
    return {area / w, w};
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
    int area;
    cin >> area;

    vector<int> result = sol.constructRectangle(area);

    for (const auto& it : result) {
      cout << it << " ";
    }
    cout << "\n";
  }

  return 0;
}