#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumBoats(int n, vector<int>& weights, int weightLimit) {
    int n = weights.size();

    sort(weights.begin(), weights.end());

    int i = 0;
    int j = n - 1;
    int boats = 0;

    while(i <= j) {
      if (weights[i] + weights[j] <= weightLimit) {
        i++;
      }
      j--;
      boats++;
    }
    return boats;
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
    cin >> n;

    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
      cin >> weights[i];
    }

    int weightLimit;
    cin >> weightLimit;

    cout << sol.minimumBoats(n, weights, weightLimit) << '\n';
  }

  return 0;
}