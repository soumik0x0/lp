#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
            count++;
          }
        }
      }
    }
    return count;
  }
};

class Solution2 {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i <= n - 3; i++) {
      for (int j = i + 1; j <= n - 2; j++) {
        if (abs(arr[i] - arr[j]) <= a) {
          for (int k = j + 1; k <= n - 1; k++) {
            if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
              count++;
            }
          }
        }
      }
    }
    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  vector<int> arr = {1, 1, 2, 2, 3};
  int a = 0;
  int b = 0;
  int c = 1;

  cout << sol1.countGoodTriplets(arr, a, b, c) << endl;
  cout << sol2.countGoodTriplets(arr, a, b, c) << endl;

  return 0;
}