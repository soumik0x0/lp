#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.length();

    vector<int> result;

    vector<int> mp(26, -1);

    for (size_t i = 0; i < n; i++) {
      int idx = s[i] - 'a';
      mp[idx] = i;
    }

    int i = 0;
    int start = 0;
    int end = 0;

    while (i < n) {
      end = max(mp[s[i] - 'a'], end);
      if (i == end) {
        result.push_back(end - start + 1);
        start = end + 1;
      }
      i++;
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  string s = "cristiano";

  vector<int> result = sol.partitionLabels(s);
  
  for (const auto &i : result) {
    cout << i << " ";
  }

  return 0;
}
