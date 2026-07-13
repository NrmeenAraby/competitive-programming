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
const int MAX = 3e5 + 5;
const int MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>f(n+1),d(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        for (int i = 2; i <= n; i++) {
            d[i - 1] = f[i] - f[i - 1];  //d1=f2-f1 , d2=f3-f2 ....
        }
        vector<int>a(n + 1);
        for (int i = 2; i <= n; i++) {
            a[i] = (d[i] - d[i - 1]) / 2;      //a2=(d2-d1)/2
        }
        //still we dont have a1 and an
        // we know that f(1) = 0a1 + 1*a2 + 2*a3 + ... + (n-1)*an ,so from f(1) we can get an
        //(n-1)*an = f(1)-(1*a2 + 2*a3 + ...)
        ll rest = 0;
        for (int i = 2; i < n; i++) {
            rest += (i - 1) * a[i];
        }
        a[n] = (f[1] - rest) / (n - 1);
        // and to get a1, we know that d1=f(2)-f(1)=a1-(a2+a3+....+an)
        //a1=d1+(a2+a3+....+an)
        rest = 0;
        for (int i = 2; i <= n; i++) {
            rest += a[i];
        }
        a[1] = d[1] + rest;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
