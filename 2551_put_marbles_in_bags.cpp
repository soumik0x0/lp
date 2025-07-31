#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    int n = weights.size();

    vector<int> pairSum(n - 1, 0);

    for (size_t i = 0; i < n - 1; i++) {
      pairSum[i] = weights[i] + weights[i + 1];
    }

    sort(pairSum.begin(), pairSum.end());

    long long maxSum = 0;
    long long minSum = 0;

    for (size_t i = 0; i < k - 1; i++) {
      minSum += pairSum[i];
      maxSum += pairSum[n - 1 - 1 - i];
    }
    return maxSum - minSum;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> weights = {1, 3, 5, 1};
  int k = 2;

  cout << sol.putMarbles(weights, k) << endl;

  return 0;
}