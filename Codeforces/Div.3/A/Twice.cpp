#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int main() {  
    int t,n;
    cin >> t;
    while (t--) {
        cin >>n ;
        map<int, int>mp;
        int x,ans=0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (mp[x])
            {
                ans++;
                mp[x] = 0;
            }
            else
                mp[x] = 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
