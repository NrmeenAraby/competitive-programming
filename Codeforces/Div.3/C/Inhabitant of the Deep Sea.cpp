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
        long long k;
        cin >> n>>k;
        vector<long long>v(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if (sum <= k) {
            cout << n << "\n";
        }
        else {
            int ans = 0;
            long long tmp = k / 2,s,e;
            s = e = tmp;
            if (k % 2 != 0) {
                s++;
            }
            
            for (int i = 0; i < n; i++) {
                if (s > 0) {
                    s -= v[i];
                    if (s >= 0)
                        ans++;
                }
                else
                    break;
            }
            for (int i = n-1; i>=0; i--) {
                if (e > 0) {
                    e -= v[i];
                    if (e >= 0)
                        ans++;
                }
                else
                    break;
            }
            cout << ans << "\n";
        }

    }
    return 0;
}
