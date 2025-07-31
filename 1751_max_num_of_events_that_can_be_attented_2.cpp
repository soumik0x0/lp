#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

//Using Recursion w/o memoization and with linear search
class Solution1 { //T.C : O(2^n)
public:
  int n;
  int solve(vector<vector<int>>& events, int i, int k) {
    
    if (k <= 0 || i >= n) {
      return 0;
    }

    int start = events[i][0];
    int end   = events[i][1];
    int value = events[i][2];

    //linear search
    int j = i + 1;
    for (; j < n; j++) {
      if (events[j][0] > events[i][1]) {
        break;
      }
    }
    
    //take
    int take = value + solve(events, j, k - 1);
    //skip
    int skip = solve(events, i + 1, k);

    return max(take, skip);
  }

  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());

    this->n = events.size();

    return solve(events, 0, k);
  }
};

//Using recursion w/ memoization and linear search
class Solution2 { //T.C : O(n.k.n)
public:
  int n;
  vector<vector<int>> dp;
  int solve(vector<vector<int>>& events, int i, int k) {

    if (k <= 0 || i >= n) {
      return 0;
    }

    if (dp[i][k] != -1) {
      return dp[i][k];
    }

    int start = events[i][0];
    int end   = events[i][1];
    int value = events[i][2];

    //linear seach
    int j = i + 1;
    for (; j < n; j++) {
      if (events[j][0] > events[i][1]) {
        break;
      }
    }

    //take
    int take = value + solve(events, j, k - 1);
    //skip
    int skip = solve(events, i + 1, k);

    return dp[i][k] = max(take, skip);
  }

  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());

    this->n = events.size();

    dp.resize(n + 1, vector<int>(k + 1, -1));

    return solve(events, 0, k);
  }
};

//using recursion w/ memoization and binary search(C++ STL -> std::upper_bound)
class Solution3 { //T.C : O(n.k.log(n))
public:
  int n;
  vector<vector<int>> dp;
  int solve(vector<vector<int>>& events, int i, int k) {

    if (k <= 0 || i >= n) {
      return 0;
    }

    if (dp[i][k] != -1) {
      return dp[i][k];
    }

    int start = events[i][0];
    int end   = events[i][1];
    int value = events[i][2];

    //binary search -> finding the next event's index which can be attented
    vector<int> temp = {end, INT_MAX, INT_MAX};
    int j = upper_bound(events.begin(), events.end(), temp) - events.begin();

    //take
    int take = value + solve(events, j, k - 1);
    //skip
    int skip = solve(events, i + 1, k);

    return dp[i][k] = max(take, skip);
  }

  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());

    this->n = events.size();

    dp.resize(n + 1, vector<int>(k + 1, -1));

    return solve(events, 0, k);
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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> events(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
      cin >> events[i][0] >> events[i][1] >> events[i][2];
    }

    cout << sol1.maxValue(events, k) << "\n";
    cout << sol2.maxValue(events, k) << "\n";
    cout << sol3.maxValue(events, k) << "\n";
  }

  return 0;
}