#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<char> reverseString(vector<char> &s) {
    stack<char> st;

    for (size_t i = 0; i < s.size(); i++) {
      st.push(s[i]);
    }

    size_t i = 0;
    while (!st.empty()) {
      s[i] = st.top();
      st.pop();
      i++;
    }
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<char> s = {'h', 'e', 'l', 'l', 'o'};

  Solution sol;

  vector<char> result = sol.reverseString(s);
  
  for (const auto &c : result) {
    cout << c << " ";
  }

  cout << endl;

  return 0;
}