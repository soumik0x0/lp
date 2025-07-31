#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkDivisibility(int n) {
    int original = n;
    int digit_sum = 0;
    int digit_product = 1;

    while (n > 0) {
      int digit = n % 10;
      digit_sum += digit;
      digit_product *= digit;
      n /= 10;
    }

    int total = digit_sum + digit_product;

    return (original % total == 0);
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

    cout << boolalpha << sol.checkDivisibility(n) << "\n";
  }

  return 0;
}