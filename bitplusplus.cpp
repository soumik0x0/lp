#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<string> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << count(v.begin(), v.end(), "++X") 
       + count(v.begin(), v.end(), "X++") 
       - count(v.begin(), v.end(), "--X") 
       - count(v.begin(), v.end(), "X--") << "\n";

  return 0;
}
