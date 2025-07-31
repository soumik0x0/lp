#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> subsets(const vector<int> &nums)
  {
    int n = nums.size();
    int subset_count = (1 << n);
    vector<vector<int>> subsets;

    for (size_t mask = 0; mask < subset_count; mask++)
    {
      vector<int> subset;
      for (size_t i = 0; i < n; i++)
      {
        if (mask & (1 << i))
        {
          subset.push_back(nums[i]);
        }
      }
      subsets.push_back(subset);
    }
    return subsets;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums = {1, 2, 3};

  vector<vector<int>> result = sol.subsets(nums);

  cout << "[";
  for (size_t i = 0; i < result.size(); i++)
  {
    cout << "[";
    for (size_t j = 0; j < result[i].size() - 1; j++)
    {
      cout << result[i][j];
      if (j != result[i].size() - 1) cout << ", ";
    }
    cout << "]";
    if (i != result.size() - 1) cout << ", ";
  }

  cout << "]" << endl;

  return 0;
}