//T.C : O(log(n - k - 1))
//S.C : O(n)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static constexpr int M = 1e9 + 7;

  long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact) {
    return factorial[n] * fermatFact[n - r] % M * fermatFact[r] % M;
  }

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

  int countGoodArrays(int n, int m, int k) {
    vector<long long> factorial(n + 1, 1);
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= n; i++) {
      factorial[i] = factorial[i - 1] * i % M;
    }

    vector<long long> fermatFact(n + 1, 1);
    for (int i = 0; i <= n; i++) {
      fermatFact[i] = findPower(factorial[i], M - 2);
    }

    long long result = nCr(n - 1, k, factorial, fermatFact);

    result = result * m % M;

    result = result * findPower(m - 1, n - k -1) % M;

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
    int n, m, k;
    cin >> n >> m >> k;

    cout << sol.countGoodArrays(n, m, k) << endl;
  }

  return 0; 
}