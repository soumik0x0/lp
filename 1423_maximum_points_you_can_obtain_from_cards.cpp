#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;

    for (int i = 0; i < k; i++) {
      leftSum += cardPoints[i];
    }

    maxSum = leftSum;

    int rightIdx = cardPoints.size() - 1;

    for (int i = k - 1; i >= 0; i--) {
      leftSum -= cardPoints[i];
      rightSum += cardPoints[rightIdx];
      rightIdx--;

      maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
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
    int n, k;
    cin >> n >> k;

    vector<int> cardPoints(n);

    for (int i = 0; i < n; i++) {
      cin >> cardPoints[i];
    }

    cout << sol.maxScore(cardPoints, k) << "\n";
  }

  return 0;
}