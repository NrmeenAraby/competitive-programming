#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <array>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <functional>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <list>
#define ll  long long
using namespace std;


int main() {
    // (ai+aj)%x=0  -> ( ai%x + aj%x )%x=0 -> (ai%x + aj%x) = 0 or x -> aj%x = (x-(ai%x))%x
    // (ai-aj)%y=0 -> (ai%y)-(aj%y)=0 ->(ai%y)=(aj%y)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
  
    while (t--) {
        int n;
        ll x, y;
        cin >> n>>x>>y;
        vector<ll>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<ll, map<ll, ll>>mp;
        ll ans = 0;
        for (int j = 0; j < n; j++) {
            ans += mp[(x - (a[j] % x)) % x][a[j] % y];   //x-(a[j]%x) % x handles both x and 0 as if a[j]=0 >> (x-0)%x=0
            mp[a[j] % x][a[j] % y]++;
        }
        cout << ans << endl;
    }
    
    return 0;
}
