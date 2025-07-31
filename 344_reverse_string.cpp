#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<char> reverseString(vector<char> &s)
  {
    int st = 0;
    int end = s.size() - 1;

    while (st < end)
    {
      swap(s[st++], s[end--]);
    }
    return s;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<char> s = {'h', 'e', 'l', 'l', 'o'};

  Solution sol;
  vector<char> result = sol.reverseString(s);

  for (const auto &c : result)
  {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}