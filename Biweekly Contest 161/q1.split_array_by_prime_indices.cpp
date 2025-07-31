#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool isPrime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }

public:
  long long splitArray(vector<int>& nums) {
    long long sumA = 0, sumB = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (isPrime(i)) {
        sumA += nums[i];
      } else {
        sumB += nums[i];
      }
    }

    return abs(sumA - sumB);
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

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol.splitArray(nums) << "\n";
  }

  return 0;
}