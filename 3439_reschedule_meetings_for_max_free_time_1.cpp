//T.C : O(n)
//S.C : O(n)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<int> freeGap; //calculating total free time available

    freeGap.push_back(startTime[0]);

    for (int i = 1; i < startTime.size(); i++) {
      freeGap.push_back(startTime[i] - endTime[i - 1]);
    }

    freeGap.push_back(eventTime - endTime[endTime.size() - 1]);

    int i = 0;
    int j = 0;
    int maxSum = 0;
    int currSum = 0;
    int n = freeGap.size();

    //sliding window on the available free time to extract the longest continous free time
    while (j < n) {
      currSum += freeGap[j];

      if (i < n && j - i + 1 > k + 1) { //k + 1 -> because shifting one event frees two gaps
        currSum -= freeGap[i];
        i++;
      }

      maxSum = max(maxSum, currSum);
      j++;
    }

    return maxSum;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;

  while (t--) {
    int eventTime, k, m;
    cin >> eventTime >> k >> m;

    vector<int> startTime(m);
    vector<int> endTime(m);

    for (int i = 0; i < m; i++) {
      cin >> startTime[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> endTime[i];
    }

    cout << sol.maxFreeTime(eventTime, k, startTime, endTime) << "\n";
  }

  return 0;
}