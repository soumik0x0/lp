#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countStudents(vector<int>& books, int pages) {
    int students = 1;
    int pageStudent = 0;

    for (int i = 0; i < books.size(); i++) {
      if (pageStudent + books[i] <= pages) {
        pageStudent += books[i];
      } else {
        students += 1;
        pageStudent = books[i];
      }
    }

    return students;
  } 

  int spliArray(vector<int>& nums, int k) {
    if (k > nums.size()) return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (countStudents(nums, mid) > k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int T;
  cin >> T;

  while (T--) {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    cout << sol.spliArray(nums, k) << "\n";
  }

  return 0;
}