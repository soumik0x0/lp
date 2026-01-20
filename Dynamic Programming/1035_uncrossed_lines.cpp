#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int m, n;

  int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
    if (i >= m || j >= n) {
      return 0;
    }

    if (nums1[i] == nums2[j]) {
      return 1 + solve(i + 1, j + 1, nums1, nums2);
    } else {
      int fix_i = solve(i, j + 1, nums1, nums2);
      int fix_j = solve(i + 1, j, nums1, nums2);

      return max(fix_i, fix_j);
    }
  }

  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    m = nums1.size();
    n = nums2.size();

    return solve(0, 0, nums1, nums2);
  }
};

class Solution2 {
public:
  int m, n;
  int t[501][501];

  int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
    if (i >= m || j >= n) {
      return 0;
    }

    if (t[i][j] != -1) {
      return t[i][j];
    }

    if (nums1[i] == nums2[j]) {
      return t[i][j] = 1 + solve(i + 1, j + 1, nums1, nums2);
    } else {
      int fix_i = solve(i, j + 1, nums1, nums2);
      int fix_j = solve(i + 1, j, nums1, nums2);

      return t[i][j] = max(fix_i, fix_j);
    }
  }

  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    m = nums1.size();
    n = nums2.size();

    memset(t, -1, sizeof(t));

    return solve(0, 0, nums1, nums2);
  }
};

class Solution3 {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (i == 0 || j == 0) {
          t[i][j] = 0;
        } else if (nums1[i - 1] ==  nums2[j - 1]) {
          t[i][j] = 1 + t[i - 1][j - 1];
        } else {
          t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
      }
    }

    return t[m][n];
  }
};

class Solution4 {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    int t[501][501];

    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (i == 0 || j == 0) {
          t[i][j] = 0;
        } else if (nums1[i - 1] == nums2[j - 1]) {
          t[i][j] = 1 + t[i - 1][j - 1];
        } else {
          t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
      }
    }

    return t[m][n];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;
  Solution3 sol3;
  Solution4 sol4;

  int T;
  cin >> T;

  while (T--) {
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m);
    vector<int> nums2(n);

    for (int i = 0; i < m; i++) {
      cin >> nums1[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> nums2[i];
    }

    cout << sol1.maxUncrossedLines(nums1, nums2) << "\n";
    cout << sol2.maxUncrossedLines(nums1, nums2) << "\n";
    cout << sol3.maxUncrossedLines(nums1, nums2) << "\n";
    cout << sol4.maxUncrossedLines(nums1, nums2) << "\n";
  }

  return 0;
}