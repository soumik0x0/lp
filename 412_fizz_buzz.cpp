#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> answer(n);

    for (int i = 1; i <= n; i++) {
      answer[i - 1] = to_string(i);
    }

    for (int i = 2; i < n; i += 3) {
      if (answer[i] != "Buzz") {
        answer[i] = "Fizz";
      }
    }

    for (int i = 4; i < n; i += 5) {
      if (answer[i] != "Fizz") {
        answer[i] = "Buzz";
      }
    }

    for (int i = 14; i < n; i += 15) {
      answer[i] = "FizzBuzz";
    }

    return answer;
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
    int n;
    cin >> n;

    vector<string> answer = sol.fizzBuzz(n);

    for (const auto& it : answer) {
      cout << it << " ";
    }

    cout << "\n";
  }

  return 0;
}
