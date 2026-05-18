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
vector<vector<ll>>sp;
vector<ll>lg;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void preLog(int n) { //O(n)
    lg.resize(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}
ll merge(ll a, ll b) {
    return max(a, b);
}
void buildSP(vector<ll>& v) {  //nlogn
    int n = v.size();
    sp.resize(n, vector<ll>(25, 0));
    for (int i = 0; i < n; i++) {
        sp[i][0] = v[i];
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; (i + (1 << pw)) <= n; i++) {
            sp[i][pw] = merge(sp[i][pw - 1], sp[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}
ll query(int l, int r) { //O(1)
    int sz = r - l + 1;
    ll pw = lg[sz];      //greatest power that gives length less than or equal r
    return merge(sp[l][pw], sp[r - (1 << pw) + 1][pw]);
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
        vector<ll>a(n);
        ll tmpMxMon = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tmpMxMon = max(tmpMxMon, a[i]);
        }
        int m;
        cin >> m;
        int p, s;
        vector<int>processedHeroes(n + 1);
        int flag = 0;
        for (int i = 0; i < m; i++) {
            cin >> p >> s;
            if (p >= tmpMxMon)
                flag = 1;
            processedHeroes[s] = max(processedHeroes[s], p);
        }
        if (flag == 0)
            cout << -1 << endl;
        else{
            preLog(n);
            buildSP(a);
        //suffix max so i can check the cuurent length(this suffix cancels heroes have less values (power and s) than other available heroes)
        // also it is okay to have in the array some s that isnt exist(as the processedHeroes use all n+1 wether this s mentioned or not) as it wont hurt while checking the current length
        for (int i = n - 1; i >= 0; i--) {
            processedHeroes[i] = max(processedHeroes[i], processedHeroes[i + 1]);
        }  // so it is guaranteed that as s increases, the power is either the same or less >> so i can do the length check safely

        int j = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < n) {
                int mxMonPow = query(i, j);
                int len = j - i + 1;
                if (processedHeroes[len] >= mxMonPow) {
                    j++;
                }
                else {
                    break;
                }
            }
            ans++;
            i = j-1; //as the for loop do i++ so i will be j in the iteration as we want 
        }
        cout << ans << endl;
      }
    }   
    return 0;
}
