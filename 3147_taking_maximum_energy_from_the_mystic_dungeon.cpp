#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int n;
  int K;

  int solve(int i, vector<int>& energy) {
    if (i >= n) {
      return 0;
    }

    return energy[i] + solve(i + K, energy);
  }

  int maximumEnergy(vector<int>& energy, int k) {
    n = energy.size();
    K = k;

    int maxEnergy = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxEnergy = max(maxEnergy, solve(i, energy));
    }

    return maxEnergy;
  }
};

class Solution2 {
public:
  int n;
  int K;

  int solve(int i, vector<int>& energy, vector<int>& t) {
    if (i >= n) {
      return 0;
    }

    if (t[i] != INT_MIN) {
      return t[i];
    }

    return t[i] = energy[i] + solve(i + K, energy, t);
  }

  int maximumEnergy(vector<int>& energy, int k) {
    n = energy.size();
    K = k;
    vector<int> t(n, INT_MIN);

    int maxEnergy = INT_MIN;

    for (int i = 0; i < n; i++) {
      maxEnergy = max(maxEnergy, solve(i, energy, t));
    }

    return maxEnergy;
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
    int n, k;
    cin >> n >> k;
    vector<int> energy(n);

    for (int i = 0; i < n; i++) {
      cin >> energy[i];
    }

    cout << sol1.maximumEnergy(energy, k) << "\n";
    cout << sol2.maximumEnergy(energy, k) << "\n";
  }

  return 0;
}