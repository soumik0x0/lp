#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static constexpr int M = 1e9 + 7;

  long long findPower(long long a, long long b) {
    if (b == 0) {
      return 1;
    }

    long long half = findPower(a, b/2);
    long long result = (half * half) % M;

    if (b % 2 == 1) {
      result = (result * a) % M;
    }
    return result;
  }

  long long countGoodNumbers(long long n) {
    return (long long) findPower(5, (n + 1)/2) * findPower(4, n/2) % M;
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
    long long n;
    cin >> n;

    cout << sol.countGoodNumbers(n) << endl;
  }

  return 0;
}