#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findWordsContaining(vector<string>& words, char x)
    {
      vector<int> result;

      for (int i = 0; i < words.size(); i++)
      {
        if (count(words[i].begin(), words[i].end(), x)) result.push_back(i);
      }
      return result;
    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  Solution sol;

  while(t--)
  {
    int n;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
      cin >> words[i];
    }

    char x;
    cin >> x;

    vector<int> result = sol.findWordsContaining(words, x);

    for (const auto& idx : result)
    {
      cout << idx << " ";
    }
    cout << endl;
  }

  return 0;
}