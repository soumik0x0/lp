#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    unordered_map<int, int> map;

    for (int &x : answers) {
      map[x]++;
    }

    int total = 0;

    for (auto &it : map) {
      int x = it.first;
      int count = it.second;

      int groupSize = x + 1;
      int groups = ceil((double) count / groupSize);

      total += groups * groupSize;
    }
    return total;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> answers = {10, 10, 10};

  cout << sol.numRabbits(answers) << endl;

  return 0;
}