// Using STL
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
  {
    set<int> st1(nums1.begin(), nums1.end());
    set<int> st2(nums2.begin(), nums2.end());

    vector<int> v1, v2;

    set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(v1));
    set_difference(st2.begin(), st2.end(), st1.begin(), st1.end(), back_inserter(v2));

    return {v1, v2};
  }
};

void print2DVector(const vector<vector<int>> &vec)
{
  cout << "[";
  for (size_t i = 0; i < vec.size(); i++)
  {
    cout << "[";
    for (size_t j = 0; j < vec[i].size(); j++)
    {
      cout << vec[i][j];
      if (j != vec[i].size() - 1)
        cout << ", ";
    }
    cout << "]";
    if (i != vec.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  vector<int> nums1 = {1, 2, 3, 3};
  vector<int> nums2 = {1, 1, 2, 2};

  vector<vector<int>> result = sol.findDifference(nums1, nums2);

  print2DVector(result);

  return 0;
}
