#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countTriples(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          if (pow(i, 2) + pow(j, 2) == pow(k, 2)) {
            count++;
          }
        }
      }
    }
    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  cout << sol.countTriples(5) << endl;

  return 0;
}