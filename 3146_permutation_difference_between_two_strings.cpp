#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPermutationDifference(string s, string t) {
    int diff = 0;

    for (int i = 0; i < s.length(); i++) {
      int j = t.find(s[i]);
      diff += abs(j - i);
    }
    return diff;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  string s = "abc";
  string t = "bac";

  cout << sol.findPermutationDifference(s, t) << endl;

  return 0;
}