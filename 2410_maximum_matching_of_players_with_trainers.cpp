#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {//will not pass for all the test cases
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    int n = players.size();
    int m = trainers.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (trainers[j] >= players[i]) {
          count++;
          trainers[j] = -1;
          break;
        }
      }
    }

    return count;
  }
};

class Solution2 {
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int n = players.size();
    int m = trainers.size();

    int count = 0;
    int i     = 0;
    int j     = 0;
    
    while (i < n && j < m) {
      if (players[i] > trainers[j]) {
        j++;
      } else {
        count++;
        i++;
        j++;
      }
    }

    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  //Solution1 sol1;
  Solution2 sol2;

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> players(n);
    vector<int> trainers(m);

    for (int i = 0; i < n; i++) {
      cin >> players[i];
    }

    for (int j = 0; j < m; j++) {
      cin >> trainers[j];
    }

    cout << sol2.matchPlayersAndTrainers(players, trainers) << "\n";
  }

  return 0;
}