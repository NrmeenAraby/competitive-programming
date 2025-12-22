#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <numeric>
#include<queue>
#include<array>
using namespace std;
const long long MAX = 1e18;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        if (n % 2 == 0)
            ans++;
        if (n % 4 == 0)
            ans++;
        int chk = 2;
        while (chk < n) {
            int rem = n - chk;
            if (rem % 4 == 0)
                ans++;
            chk += 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
