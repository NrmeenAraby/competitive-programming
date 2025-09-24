#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t,m,a,b,c;
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> m>>a>>b>>c;
        long long rem = 0;
        if (a >= m)
            ans += m;
        else {
            ans += a;
            rem = m - a;
        }

        if (b >= m)
            ans += m;
        else {
            ans += b;
            rem += m - b;
        }

        if (c >= rem)
            ans += rem;
        else
            ans += c;

        cout << ans << "\n";
    }
    return 0;
}
