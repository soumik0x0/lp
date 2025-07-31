#pragma GCC optimize("O3")
#include <bits/stdc++.h>

[[nodiscard]] inline std::vector<int> plusOne(std::vector<int>& digits)
{
  for (int i = digits.size() - 1; i >= 0; i--)
  {
    if (digits[i] < 9)
    {
      digits[i]++;
      return digits;
    }
    digits[i] = 0;
  }

  std::vector<int> result(digits.size() + 1, 0);
  result[0] = 1;
  return result;
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
    int n;
    std::cin >> n;

    std::vector<int> digits(n);

    for (int i = 0; i < n; i++) {
      std::cin >> digits[i];
    }

    std::vector<int> result = plusOne(digits);

    for (const auto& i : result)
    {
      std::cout << i;
    }
    std::cout << std::endl;
  }

  return 0;
}