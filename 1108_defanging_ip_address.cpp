#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string defangIPaddr(string address) {
    int n = address.length();
    string result;

    for (int i = 0; i < n; i++) {
      if (address[i] == '.') {
        result += "[.]";
      } else {
        result += address[i];
      }
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
    string address;
    cin >> address;

    cout << sol.defangIPaddr(address) << "\n";
  }

  return 0;
}