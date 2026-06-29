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
const int MAX = 2e5 + 5;
const int MOD = 1e8;
int n;
vector<int>x,h;
int dp[MAX][2];
int solve(int idx=1,int prev=0) { //prev:   1>>  prev tree was cut to the right

    if (idx == n)
        return 0;
    if (idx == n-1) //last tree can be cut to the right always
        return 1;

    if (dp[idx][prev] != -1)
        return dp[idx][prev];

    dp[idx][prev] = max(dp[idx][prev], solve(idx + 1, 0)); //isnt cut down

    if (idx + 1 < n) {  //right
        if (x[idx] + h[idx] < x[idx + 1]) {
            dp[idx][prev] = max(dp[idx][prev], solve(idx + 1, 1)+1); 
        }
    }

    int tmp = 0;
    if (prev)
        tmp = h[idx - 1];

    if (x[idx] - h[idx] > x[idx - 1] +tmp)  //left
    {
            dp[idx][prev] = max(dp[idx][prev], solve(idx + 1, 0) + 1);
    }
    
    return dp[idx][prev];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
   // cin >> t;
    while (t--) {
        cin >> n;
        x.resize(n);
        h.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i]>>h[i];
        }
        memset(dp, -1, sizeof dp);

        cout << 1+solve()<<endl; //first tree can be cut to the left always
    }
    return 0;
}
