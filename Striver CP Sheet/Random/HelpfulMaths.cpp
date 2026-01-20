#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  vector<int> nums;
  for (int i = 0; i < s.size(); i += 2) {
    nums.push_back(s[i] - '0');
  }

  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() ; i++) {
    if (i > 0) cout << "+";
    cout << nums[i];
  }
  cout << endl;

  return 0;
}