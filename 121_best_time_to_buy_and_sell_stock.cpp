#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int maxProfit = 0;

    int buy = prices[0];

    for (int j = 1; j < n; j++) {
      if (buy < prices[j]) {
        maxProfit = max(maxProfit, prices[j] - buy);
      } else {
        buy = prices[j];
      }
    }
    return maxProfit;
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

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
      cin >> prices[i];
    }

    cout << sol.maxProfit(prices) << endl;
  }

  return 0;
}