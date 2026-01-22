#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("in.txt", "r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int move = n - m;
        int mn = min(move, r);
        r -= mn;
        move -= mn;
        if (move>0) {
            l += move;
        }
        cout << l << " " << r << "\n";
    }
    return 0;
}
