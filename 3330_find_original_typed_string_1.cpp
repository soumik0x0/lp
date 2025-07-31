#pragma GCC optimize("O3")
#include <bits/stdc++.h>

[[nodiscard]] inline int possibleStringCount(std::string word)
{
  int n = word.length();

  int  count = 0;

  for (int i = 1; i < n; i++)
  {
    if (word[i] == word[i - 1])
    {
      count++;
    }
  }
  return count + 1;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while(t--)
  {
    std::string word;
    std::cin >> word;

    std::cout << possibleStringCount(word) << "\n";
  }

  return 0;
}