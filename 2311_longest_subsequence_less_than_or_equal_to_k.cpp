#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
private:
  int solve(string& s, int k, int n, int i) {
    //Base case
    if (i < 0) {
      return 0;
    }

    int bit = s[i] - '0';

    int value = pow(2, n - i - 1) * bit;

    int take = 0;
    int skip = 0;

    if (k >= value) {
      take = 1 + solve(s, k - value, n, i - 1);
    }

    skip = solve(s, k, n, i - 1);

    return max(skip, take);
  }

public:
  int longestSubsequence(string s, int k) {
    return solve(s, k, s.length(), s.length() - 1);
  }
};

class Solution2 {
public:
  int longestSubsequence(string s, int k) {
    int n = s.length();

    int length = 0;

    int binaryPowerValue = 1; //ye (n - 1)th bit ka power value hain => 2^0

    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        length++;
      } else if (binaryPowerValue <= k) {
        k -= binaryPowerValue;
        length++;
      }

      if (binaryPowerValue <= k) {
        binaryPowerValue <<= 1; //iska matlab hain left shift karna basically binaryPowerValue *= 2;
      }
    }
    return length;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int t;
  cin >> t;

  while(t--) {
    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << sol1.longestSubsequence(s, k) << "\n";
    cout << sol2.longestSubsequence(s, k) << "\n";
  }

  return 0;
}