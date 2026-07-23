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
vector<int>l, r;
ll path_to_parent[MAX], ans[MAX]; //path_to_parent[v] holds num of seconds to reach the parent of v, while ans[v] holds num of seconds to reach to the root 0

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
        int x,prev;
        int flag = 0;
        cin >> prev;
        for (int i = 1; i < n; i++) {
            cin >> x;
            if (prev > x)
                flag = 1;
            prev = x;
        }
        if (flag)
            cout << 1 << endl;
        else 
            cout << n << endl;
         
    }
    return 0;
}
