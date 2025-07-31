#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int num = low; num <= high; num++) {
      string s = to_string(num);

      int l = s.length();

      int leftSum = 0;
      int rightSum = 0;

      if (l % 2 != 0) {
        continue;
      }

      for (int i = 0; i < l/2; i++) {
        leftSum += s[i] - '0';
      }

      for (int i = l/2; i < l; i++) {
        rightSum += s[i] - '0';
      }

      if (leftSum == rightSum) {
        count++;
      }
    }
    return count;
  }
};

class Solution2 {
public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int i = low; i <= high; i++) {
      if (i >= 10 && i <= 99 && i % 11 == 0) {
        count++;
      } else if (i >= 1000 && i <= 9999) {
        int first = i / 1000;
        int second = (i / 100) % 10;
        int third = (i / 10) % 10;
        int fourth = i % 10;

        if (first + second == third + fourth) {
          count++;
        }
      }
    }
    return count;
  }
};

class Solution3 {
public:
  int countSymmetricIntegers(int low, int high) {
    
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int low = 1200;
  int high = 1230;

  cout << sol1.countSymmetricIntegers(low, high) << endl;
  cout << sol2.countSymmetricIntegers(low, high) << endl;

  return 0;
}