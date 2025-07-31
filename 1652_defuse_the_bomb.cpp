#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();

    vector<int> result(n, 0);

    if (k == 0) return result;

    for (int i = 0; i < n; i++) {
      if (k > 0) {
        for (int j = i + 1; j <= i + k; j++) {
          result[i] += code[j % n];
        }
      } else if (k < 0) {
        for (int j = i - abs(k); j < i; j++) {
          result[i] += code[(j + n) % n];
        }
      }
    }

    return result;
  }
};

class Solution2 {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();

    vector<int> result(n, 0);

    if (k == 0) return result;

    int i = -1;
    int j = -1;

    if (k > 0) {
      i = 1;
      j = k;
    } else if (k < 0) {
      i = n - abs(k);
      j = n - 1;
    }

    int windowSum = 0;

    for (int pointer = i; pointer <= j; pointer++) {
      windowSum += code[pointer];
    }

    for (int k = 0; k < n; k++) {
      result[k] = windowSum;

      windowSum -= code[i % n];
      i++;

      windowSum += code[(j + 1) % n];
      j++;
    }

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int T;
  cin >> T;

  while (T--) {
    int n, k;
    cin >> n >> k;

    vector<int> code(n);

    for (int i = 0; i < n; i++) {
      cin >> code[i];
    }

    vector<int> result1 = sol1.decrypt(code, k);
    vector<int> result2 = sol2.decrypt(code, k);

    for (const auto& it : result1) {
      cout << it << " ";
    }
    cout << "\n";

    for (const auto& it : result2) {
      cout << it << " ";
    }
    cout << "\n"; 
  }

  return 0;
}