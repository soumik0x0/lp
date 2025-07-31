#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  set<pair<string, string>> leaves;

public:
  void addLeaf(string species, string colour) {
    leaves.insert({species, colour});
  }

  int getDistinctLeafCount() const {
    return leaves.size();
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
    string species, colour;
    cin >> species >> colour;
    sol.addLeaf(species, colour);
  }
  
  cout << sol.getDistinctLeafCount() << "\n";

  return 0;
}
