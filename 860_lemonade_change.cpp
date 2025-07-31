#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool lemnoadeChange(vector<int> &bills) {
    int five = 0;
    int ten = 0;

    for (auto &bill : bills) {
      if (bill == 5) {
        five++;
      } else if (bill == 10) {
        if (five > 0) {
          five--;
          ten++;
        } else {
          return false;
        }
      } else if (five > 0 && ten > 0) {
        five--;
        ten--;
      } else if (five >= 3) {
        five -= 3;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> bills = {5, 5, 5, 10, 20};

  cout << boolalpha << sol.lemnoadeChange(bills) << endl;

  return 0;
}