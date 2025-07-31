#include <bits/stdc++.h>
using namespace std;

bool physicist(int t)
{
    int x, y, z, sum_x = 0, sum_y = 0, sum_z = 0;
    
    while(t--)
    {
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }
    
    if (sum_x == 0 && sum_y == 0 && sum_z == 0) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    __attribute__((disable_sanitizer_instrumentation));
    
    int t;
    cin >> t;
    
    bool isEquivalent = physicist(t);
    if (isEquivalent) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
    return 0;
}