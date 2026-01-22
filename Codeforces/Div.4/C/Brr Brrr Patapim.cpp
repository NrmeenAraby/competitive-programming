#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("in.txt", "r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n ;
        int x,sz=2*n+1;
        vector<int>v, check(sz);
        for(int i=1;i<=2*n;i++){
            check[i] = 0;
        }
        for (int i = 0; i < n * n; i++)
        {
            cin >> x;
            if (!check[x]) {
                check[x] = 1;
                v.push_back(x);
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (!check[i])
                cout << i << " ";
        }
        for (int i = 0; i < v.size();i++) {
            cout << v[i] << " ";
        }

        cout << "\n";
        
    }
    return 0;
}
