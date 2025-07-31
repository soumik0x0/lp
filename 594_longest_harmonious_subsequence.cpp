#pragma GCC optimize("O3")
#include <bits/stdc++.h>

[[nodiscard]] inline int findLHS1(std::vector<int>& nums)
{
  int n = nums.size();

  int j = 0;
  int maxLength = 0;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++)
  {
    while (nums[i] - nums[j] > 1)
    {
      j++;
    }

    if (nums[i] - nums[j] == 1)
    {
      maxLength = std::max(maxLength, i - j + 1);
    }
  }
  return maxLength;
}

[[nodiscard]] inline int findLHS(std::vector<int>& nums)
{
  int maxLength = 0;

  std::unordered_map<int, int> freq;

  for (const auto& i : nums)
  {
    freq[i]++;
  }

  for (const auto& [key, val] : freq)
  {
    if (freq.find(key + 1) != freq.end())
    {
      maxLength = std::max(maxLength, val + freq[key + 1]);
    }
  }
  return maxLength;
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

    std::vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
      std::cin >> nums[i];
    }

    std::cout << findLHS1(nums) << "\n";
    std::cout << findLHS(nums) << "\n";
  }

  return 0;
}