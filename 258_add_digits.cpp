#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int addDigits(int num) {
    if(num == 0) return 0;
    return num % 9 == 0 ? 9 : num % 9;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int num;
  cin >> num;

  Solution sol;

  cout << sol.addDigits(num) << endl;

  return 0;
}