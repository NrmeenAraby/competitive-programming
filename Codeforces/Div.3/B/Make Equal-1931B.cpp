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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
  
    while (t--) {
        int n;
        cin >> n;
        vector<ll>v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        int maxi = sum / n;
        ll m3aya = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > maxi) {
                m3aya += (v[i] - maxi);
                v[i] = maxi;
            }
            else if (v[i] < maxi) {
                ll needed = maxi - v[i];
                if (m3aya >= needed) {
                    v[i] = maxi;
                    m3aya -= needed;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != maxi)
            {
                flag = 1;
            }
        }
        if (flag) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    
    return 0;
}
