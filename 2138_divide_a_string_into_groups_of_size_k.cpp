#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    int n = s.length();
    vector<string> result;

    int i = 0;
    while(i < n) {
      int j = (i + k - 1 >= n) ? n - 1 : (i + k - 1);
      string temp = s.substr(i, j - i + 1);

      if (j - i + 1 < k) {
        int remaining = k - (j - i + 1);
        temp += string(remaining, fill);
      }
      result.push_back(temp);
      i += k;
    }
    return result;
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
    char fill;

    cin >> s >> k >> fill;

    vector<string> result = sol.divideString(s, k, fill);

    for (const auto& i : result) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}