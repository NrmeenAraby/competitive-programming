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
const int MAX = 2e3;
int n;
vector<int>a;
int dp[MAX][3];
int solve(int idx=0, int last=0) { //last equals 0 for nothing, 1 for contest or 2 for gym
    if (idx == n)
        return 0;

    if (dp[idx][last] != -1)
        return dp[idx][last];

    dp[idx][last] = MAX;
    if (a[idx] == 3 && last == 0) {
        dp[idx][last] = min(dp[idx][last], solve(idx + 1, 1));
        dp[idx][last] = min(dp[idx][last], solve(idx + 1, 2));
    }
    else if(a[idx]==3) {
        if(last==2)
            dp[idx][last] = min(dp[idx][last], solve(idx + 1, 1));
        else if (last==1)
            dp[idx][last] = min(dp[idx][last], solve(idx + 1, 2));
    }
    else if (a[idx] == 0) {
        dp[idx][last] = min(dp[idx][last], solve(idx + 1, 0) + 1); //leave
    }
    else if ( a[idx] != last) {
        dp[idx][last] = min(dp[idx][last], solve(idx + 1, a[idx]));
        
    }
 
    if(a[idx]!=0)  // as 0 already added its 1
     dp[idx][last] = min(dp[idx][last], solve(idx + 1, 0) + 1); //leave

    return dp[idx][last];

}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
  //  cin >> t;
    while (t--) {
        cin >> n ;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        cout<<solve()<<endl;
    }
    return 0;
}
