#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistance(string s, int k) {
    int maxMD = 0;

    int north = 0;
    int south = 0;
    int east = 0;
    int west = 0;

    for (size_t i = 0; i < s.length(); i++) {
      if (s[i] == 'N') north++;
      else if (s[i] == 'S') south++;
      else if (s[i] == 'E') east++;
      else if (s[i] == 'W') west++;

      int currMD = abs(east - west) + abs(north - south);

      int steps = i + 1;
      int wastedSteps = steps - currMD;

      int extraSteps = 0;
      
      if (wastedSteps != 0) {
        extraSteps = min(2*k, wastedSteps);
      }

      int finalCurrMD = currMD + extraSteps;

      maxMD = max(maxMD, finalCurrMD);
    }
    return maxMD;
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
    string s;
    
    int k;

    cin >> s >> k;

    cout << sol.maxDistance(s, k) << endl;
  }

  return 0;
}