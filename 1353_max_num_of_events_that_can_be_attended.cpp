#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    int n = events.size();

    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;
    int count = 0;
    int day = events[0][0];

    while (i < n || !pq.empty()) {

      if (pq.empty()) {
        day = events[i][0];
      }

      while (i < n && events[i][0] == day) {
        pq.push(events[i][1]);
        i++;
      }

      if (!pq.empty()) {
        pq.pop();
        count++;
      }

      day++;

      while (!pq.empty() && pq.top() < day) {
        pq.pop();
      }
    }

    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> events(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
      cin >> events[i][0] >> events[i][1];
    }

    cout << sol.maxEvents(events) << "\n";
  }

  return 0;
}