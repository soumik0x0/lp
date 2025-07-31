#pragma GCC optimize("O3")
#include <bits/stdc++.h>

[[nodiscard]] inline bool containsDuplicate1(std::vector<int>& nums)
{
  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[i] == nums[j])
      {
        return true;
      }
    }
  }

  return false;
}

[[nodiscard]] inline bool containsDuplicate2(std::vector<int>& nums)
{
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == nums[i + 1])
    {
      return true;
    }
  }

  return false;
}

[[nodiscard]] inline bool containsDuplicate3(std::vector<int>& nums)
{
  return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
}

[[nodiscard]] inline bool containsDuplicate4(std::vector<int>& nums)
{
  std::unordered_map<int, int> mp;

  for (const auto& num : nums)
  {
    mp[num]++;
  }

  for (const auto& i : mp)
  {
    if (i.second >= 2)
    {
      return true;
    }
  }

  return false;
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
    int n;
    std::cin >> n;

    std::vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
      std::cin >> nums[i];
    }

    std::cout << std::boolalpha << containsDuplicate1(nums) << "\n";
    std::cout << std::boolalpha << containsDuplicate2(nums) << "\n";
    std::cout << std::boolalpha << containsDuplicate3(nums) << "\n";
    std::cout << std::boolalpha << containsDuplicate4(nums) << "\n";
  }

  return 0;
}