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
const int INF =1e9;
const int MOD = 1e9 + 7;

int main() {
     //if all -ve, dont negate the max num
    //if all +ve or mix, dont negate the max one 
    //>> so either way keep the dont negate the maximum num
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        vector<int>a(7);
        int mx = -90,idx=0;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            if (a[i] > mx) {
                mx = a[i];
                idx = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 7; i++) {
            if(i!=idx)
               a[i]*= -1;

            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
