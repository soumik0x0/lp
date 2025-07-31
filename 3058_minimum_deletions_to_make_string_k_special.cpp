#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);

    for (const auto& ch : word) {
      freq[ch - 'a']++;
    }

    int result = word.length();

    for (size_t i = 0; i < 26; i++) {
      int deletions = 0;
      for (size_t j = 0; j < 26; j++) {
        if (i == j) {
          continue;
        } else if (freq[j] < freq[i]) {
          deletions += freq[j];
        } else if (abs(freq[j] - freq[i]) > k) {
          deletions += abs(freq[j] - freq[i]) - k;
        }
      }
      result = min(result, deletions);
    }
    return result;
  }
};

class Solution {
  public:
      int minimumDeletions(string word, int k) {
          vector<int> freq(26, 0);
  
          int result = word.length();
  
          for (const auto& ch : word) {
              freq[ch - 'a']++;
          }
  
          for (int i = 0; i < 26; i++) {
              int deleted = 0;
              for (int j = 0; j < 26; j++) {
                  if (i == j) continue;
                  else if (freq[j] < freq[i]) {
                      deleted += freq[j];
                  }
                  else if (abs(freq[j] - freq[i]) > k) {
                      deleted += abs(freq[j] - freq[i] - k);
                  }
              }
              result = min(result, deleted);
          }
          return result;
      }
  };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution sol;

  int t;
  cin >> t;

  while(t--) {
    string word;
    int k;

    cin >> word >> k;

    //cout << sol1.minimumDeletions(word, k) << endl;
    cout << sol.minimumDeletions(word, k) << endl;
  }

  return 0;
}