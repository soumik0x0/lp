#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();

    int N = n + (k - 1);
    for(int i = 0; i < k - 1; i++) {
      colors.push_back(i);
    }

    int i = 0;
    int j = 1;
    int result = 0;

    while(j < N) {
      if(colors[j] == colors[j - 1]) {
        i = j;
        j++;
        continue;
      }

      if(j - i + 1 == k) {
        result++;
        i++;
      }
      j++;
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> colors = {0, 1, 0, 1, 0};
  int k = 3;

  Solution sol;

  int answer = sol.numberOfAlternatingGroups(colors, k);

  cout << answer << endl;
  return 0;
}