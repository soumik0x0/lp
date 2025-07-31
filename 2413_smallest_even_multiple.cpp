#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int smallestEvenMultiple(int n) {
    return (n % 2 == 0) ? n : n * 2;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    Solution sol;

    int n;
    cin >> n;

    cout << sol.smallestEvenMultiple(n) << '\n';
  }
  cout << endl;

  return 0;
}