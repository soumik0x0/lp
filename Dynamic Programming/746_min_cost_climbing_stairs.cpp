#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int solve(int idx, vector<int>& cost) {
    if (idx >= cost.size()) {
      return 0;
    }

    return min((cost[idx] + solve(idx + 1, cost)), (cost[idx] + solve(idx + 2, cost)));
  }

  int minCostClimbingStairs(vector<int>& cost) {
    return min(solve(0, cost), solve(1, cost));
  }
};

class Solution2 {
public:
  int t[1001];

  int solve(int idx, vector<int>& cost) {
    if (idx >= cost.size()) {
      return 0;
    }

    if (t[idx] != -1) {
      return t[idx];
    }

    return t[idx] = min((cost[idx] + solve(idx + 1, cost)), (cost[idx] + solve(idx + 2, cost)));
  }

  int minCostClimbingStairs(vector<int>& cost) {
    memset(t, -1, sizeof(t));
    return min(solve(0, cost), solve(1, cost));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
      cin >> cost[i];
    }

    cout << sol1.minCostClimbingStairs(cost) << "\n";
    cout << sol2.minCostClimbingStairs(cost) << "\n";
  }

  return 0;
}