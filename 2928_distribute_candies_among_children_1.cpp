#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int distributeCandies(int n, int limit) {
    int result = 0;
    for (int i = 0; i <= limit; i++) {
      for (int j = 0; j <= limit; j++) {
        for (int k = 0; k <= limit; k++) {
          if (i + j + k == n) {
            result++;
          }
        }
      }
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

  while(t--) {
    int n;
    int limit;

    cin >> n >> limit;

    cout << sol.distributeCandies(n, limit) << endl;
  }

  return 0;
}