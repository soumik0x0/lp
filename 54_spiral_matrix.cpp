#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();    //row's size
    int n = matrix[0].size(); //column's size

    /*
    dir 0 : left to right
    dir 1 : top to bottom
    dir 2 : right to left
    dir 3 : bottom to top
    */

    int dir = 0;

    int top = 0;
    int bottom = m - 1;

    int left = 0;
    int right = n - 1;

    vector<int> result;

    while (top <= bottom && left <= right) {
      if (dir == 0) {
        //left to right
        //constant : top
        for (int i = left; i <= right; i++) {
          result.push_back(matrix[top][i]);
        }
        top++;
      }

      if (dir == 1) {
        //top to bottom
        //constant : right
        for (int i = top; i <= bottom; i++) {
          result.push_back(matrix[i][right]);
        }
        right--;
      }

      if (dir == 2) {
        //right to left
        //constant : bottom
        for (int i = right; i >= left; i--) {
          result.push_back(matrix[bottom][i]);
        }
        bottom--;
      }

      if (dir == 3) {
        //bottom to top
        //constant : left
        for (int i = bottom; i >= top; i--) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }

      dir = (dir + 1) % 4;
    }
    return result;
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
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }

    vector<int> result = sol.spiralOrder(matrix);

    for (const auto& num : result) {
      cout << num << " ";
    }
    cout << "\n";
  }

  return 0;
}