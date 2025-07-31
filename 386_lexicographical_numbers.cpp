#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solve(int currNum, int n, vector<int>& result) {
    if (currNum > n) {
      return;
    }

    result.push_back(currNum);

    for (int append = 0; append <= 9; append++) {
      int newNum = (currNum * 10) + append;

      if (newNum > n) {
        return;
      }

      solve(newNum, n, result);
    }
  }

  vector<int> lexicalOrder(int n) {
    vector<int> result;

    for (int startNum = 1; startNum <= 9; startNum++) {
      solve(startNum, n, result);
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
    int n;
    cin >> n;

    vector<int> result = sol.lexicalOrder(n);

    for (const auto& nums : result) {
      cout << nums << " ";
    }
    cout << endl;
  }

  return 0;
}