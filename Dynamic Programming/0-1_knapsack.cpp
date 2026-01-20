#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int knapsack(vector<int>& weights, vector<int>& values, int W, int n) {
    //base condition
    //think of the smallest valid input
    //it can be n == 0 and W == 0
    if (n == 0 || W == 0) {
      return 0;
    }

    //take or skip the weight and if taking the inputs keep decreasing the inputs for the next take and skip process
    if (weights[n - 1] <= W) {
      return max((values[n - 1] + knapsack(weights, values, W - weights[n - 1], n - 1)), knapsack(weights, values, W, n - 1));
    }

    //in this situation we can't take the weight
    // if (weights[n - 1] > W) {
    //   return knapsack(weights, values, W, n - 1);
    // }
    return knapsack(weights, values, W, n - 1);
  }
};

class Solution2 { //Recursion with memoization
private:
  int solve(vector<int>& weights, vector<int>& values, int W, int n) {
    if (n == 0 || W == 0) return 0;

    if (t[n][W] != -1) {
      return t[n][W];
    }

    if (weights[n - 1] <= W) {
      return t[n][W] = max((values[n - 1] + solve(weights, values, W - weights[n - 1], n - 1)), solve(weights, values, W, n - 1));
    }

    return t[n][W] = solve(weights, values, W, n - 1);
  }

public:
  int t[101][101]; //t[n][W] -> changing variables
  int knapsack(vector<int>& weights, vector<int>& values, int W, int n) {
    memset(t, -1, sizeof(t));

    return solve(weights, values, W, n);
  }
};

class Solution3 {
private:
  vector<vector<int>> t;
  int solve(const vector<int>& weights, const vector<int>& values, int W, int n) {
    if (n == 0 || W == 0) return 0;

    if (t[n][W] != -1) return t[n][W];

    if (weights[n - 1] <= W) {
      return t[n][W] = max(
        values[n - 1] + solve(weights, values, W - weights[n - 1], n - 1),
        solve(weights, values, W, n - 1)
      );
    }

    return t[n][W] = solve(weights, values, W, n);
  }

public:
  int knapsack(const vector<int>& weights, const vector<int>& values, int W, int n) {
    t.assign(n + 1, vector<int>(W + 1, -1));
    return solve(weights, values, W, n);
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
    int n, W;
    cin >> n >> W;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
      cin >> weights[i];
    }

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
      cin >> values[i];
    }

    cout << sol1.knapsack(weights, values, W, n) << "\n";
    cout << sol2.knapsack(weights, values, W, n) << "\n";
  }

  return 0;
}