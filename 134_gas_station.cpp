#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0, tank = 0, start = 0;
        int n = gas.size();

        for (int i = 0; i < n; ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];

            // If tank is negative, we can't start from here or any previous station
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (total_gas < total_cost) ? -1 : start;
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
    int n, m;
    cin >> n >> m;

    vector<int> gas(n);
    vector<int> cost(m);

    for (int i = 0; i < n; i++) {
      cin >> gas[i];
    }

    for (int j = 0; j < m; j++) {
      cin >> cost[j];
    }

    cout << sol.canCompleteCircuit(gas, cost) << "\n";
  }

  return 0;
}