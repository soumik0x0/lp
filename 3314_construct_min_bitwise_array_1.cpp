#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (const auto& num : nums) {
            bool found = false;

            for (int x = 0; x < num; x++) {
                if ((x | (x + 1)) == num) {
                    ans.push_back(x);
                    found = true;
                    break;
                }
            }

            if (!found) ans.push_back(-1);
        }

        return ans;
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

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<int> ans = sol.minBitwiseArray(nums);

        for (const auto& it : ans) {
            cout << it << " ";
        }

        cout << "\n";
    }

    return 0;
}