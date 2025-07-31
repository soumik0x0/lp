#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    char ch = 0;

    for (size_t i = 0; i < s.size(); i++) {
      ch ^= s[i];
    }

    for (size_t i = 0; i < t.size(); i++) {
      ch ^= t[i];
    }
    return ch;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s = "abc";
  string t = "abcd";

  Solution sol;

  cout << sol.findTheDifference(s, t) << endl;

  return 0;
}