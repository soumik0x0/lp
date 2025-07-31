#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < arr.size(); i++)
    {
      int diff = abs(arr[i] - x);
      maxHeap.push({diff, arr[i]});
    }

    if (maxHeap.size() > k)
    {
      maxHeap.pop();
    }

    vector<int> ans;

    while (!maxHeap.empty())
    {
      ans.push_back(maxHeap.top().second);
      maxHeap.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k, x;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cin >> k >> x;
  Solution sol;
  vector<int> result = sol.findClosestElements(arr, k, x);

  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}