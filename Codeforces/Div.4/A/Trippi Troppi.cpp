#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("in.txt", "r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        string s, ans = "";
        for (int i = 0; i < 3; i++)
        {
            cin >> s;
            ans += s[0];
        }
        cout << ans << "\n";
    }
    return 0;
}
