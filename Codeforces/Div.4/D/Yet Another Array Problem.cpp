
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long k,g;
        int odd = 0;
        for (int i = 0;i < n; i++) {
            cin >> k;
            if (i == 0)
                g = k;
            else {
                g = gcd(g, k);
            }
            if (k % 2 != 0)
                odd = 1;
        }
        if (odd)
            cout << 2 << "\n";
        else{
            long long ans = -1;
            for (long long x = 2; x <= 100; x++) {
                if (gcd(g, x) == 1) {
                    ans = x;
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
   
    return 0;
}
