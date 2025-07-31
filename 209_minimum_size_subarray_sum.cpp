#pragma GCC optimize("O3")
#include <bits/stdc++.h>

[[nodiscard]] inline int minSubArrayLen(int target, std::vector<int> &nums)
{
  int left = 0, right = 0, sum = 0;

  int minLength = INT_MAX;

  while (right < nums.size())
  {
    sum += nums[right];

    while (sum >= target)
    {
      minLength = std::min(minLength, right - left + 1);
      sum -= nums[left];
      left++;
    }

    right++;
  }

  return minLength == INT_MAX ? 0 : minLength;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--)
  {
    int target, n;
    std::cin >> target >> n;

    std::vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
      std::cin >> nums[i];
    }

    std::cout << minSubArrayLen(target, nums) << "\n";
  }

  return 0;
}