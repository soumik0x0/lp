#pragma GCC optimize("O3")
#include <bits/stdc++.h>

//using namespace std;

class Solution {
public:
  int maxBlocks(int s) {
    int sum = 0;
    int blocks = 0;

    for (int i = 1; i < s; i++) {
      sum += i;
      if (sum > s) {
        break;
      } else {
        blocks++;
      }
    }
    return blocks;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  Solution sol;

  int t;
  std::cin >> t;

  while(t--) {
    int s;
    std::cin >> s;

    std::cout << sol.maxBlocks(s) << "\n";
  }

  return 0;
}