#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canPermutatePalindrome(string s)
  {
    vector<int> counts(128, 0);

    for (const auto &c : s)
    {
      counts[tolower(c)]++;
    }

    int oddCount = 0;
    for (const auto &count : counts)
    {
      if (count % 2 != 0)
        oddCount++;
    }
    
    return oddCount <= 1;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    Solution sol;

    string s;
    cin >> s;

    cout << boolalpha << sol.canPermutatePalindrome(s) << '\n';
  }

  cout << endl;

  return 0;
}
