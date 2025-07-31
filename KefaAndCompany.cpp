#pragma GCC optimize("O3")
#include <bits/stdc++.h>

[[nodiscard]] inline long long maxFriendshipFactor(std::vector<std::pair<long long, long long>>& v, int d)
{
  int n = v.size();
  sort(v.begin(), v.end());
  int sum = 0, maxFactor = 0, start = 0, end = 0;

  while (start < n)
  {
    while(end < n && v[end].first - v[start].first < d)
    {
      sum += v[end].second;
      end++;
    }
    maxFactor = std::max(sum, maxFactor);
    sum -= v[start].second;
    start++;
  }
  return maxFactor;
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
    int n, d;
    std::cin >> n >> d;

    std::vector<std::pair<long long, long long>> v(n);

    for (int i = 0; i < n; i++)
    {
      std::cin >> v[i].first >> v[i].second; 
    }

    std::cout << maxFriendshipFactor(v, d) << "\n";
  }

  return 0;
}