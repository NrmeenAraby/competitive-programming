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
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int>s6, s3, s2, s1,others;
        for (int i = 0; i < n; i++) {
            if (v[i] % 6 == 0) {  
                s6.push_back(v[i]);
            }
            else if(v[i]%3==0) {
                s3.push_back(v[i]);
            }
            else if (v[i] % 2 == 0) {
                s2.push_back(v[i]);
            }
            else if (v[i]== 1) {
                s1.push_back(v[i]);
            }
            else {
                others.push_back(v[i]);
            }
        }
        for (int num : s6) {
            cout << num << " ";
        }
        for (int num : s3) {
            cout << num << " ";
        }
        for (int num : others) {
            cout << num << " ";
        }
        for (int num : s1) {
            cout << num << " ";
        }
        for (int num : s2) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
} 
