#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (const auto& num : nums2) {
      if (set1.find(num) != set1.end()) {
        result.emplace(num);
      }
    }

    return vector<int>(result.begin(), result.end());
  }
};

class Solution2 {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1(nums1.begin(), nums1.end());
    set<int> set2(nums2.begin(), nums2.end());

    vector<int> result;
    result.reserve(min(nums1.size(), nums2.size()));

    set_intersection(
      set1.begin(), set1.end(),
      set2.begin(), set2.end(),
      back_inserter(result)
    );

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

  while(T--) {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n);

    vector<int> nums2(m);

    for (int i = 0; i < n; i++) {
      cin >> nums1[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> nums2[i];
    }

    vector<int> result1 = sol1.intersection(nums1, nums2);

    vector<int> result2 = sol2.intersection(nums1, nums2);

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