#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

//Using Recursion
class Solution1 {
public:
  int solve(int idx, vector<int>& cost) {
    if (idx >= cost.size()) {
      return 0;
    }

    int a = cost[idx] + solve(idx + 1, cost);
    int b = cost[idx] + solve(idx + 2, cost);

    return min(a, b);
  }

  int minCostClimbingStairs(vector<int>& cost) {
    return min(solve(0, cost), solve(1, cost));
  }
};

//Using recursion with memoization
class Solution2 {
public:
  int dp[1001];
  int solve(int idx, vector<int>& cost) {
    if (idx >= cost.size()) {
      return 0;
    }

    if (dp[idx] != -1) {
      return dp[idx];
    }

    int a = cost[idx] + solve(idx + 1, cost);
    int b = cost[idx] + solve(idx + 2, cost);

    return dp[idx] = min(a, b);
  }

  int minCostClimbingStairs(vector<int>& cost) {
    memset(dp, -1, sizeof(dp));
    return min(solve(0, cost), solve(1, cost));
  }
};

//Using bottom-up approach
class Solution3 {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    if (n == 2) {
      return min(cost[0], cost[1]);
    }

    for (int i = 2; i < n; i++) {
      cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
    }

    //when out of bound
    return 0 + min(cost[n - 1], cost[n - 2]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;
  Solution3 sol3;

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
      cin >> cost[i];
    }

    cout << sol1.minCostClimbingStairs(cost) << "\n";
    cout << sol2.minCostClimbingStairs(cost) << "\n";
    cout << sol3.minCostClimbingStairs(cost) << "\n";
  }

  return 0;
}