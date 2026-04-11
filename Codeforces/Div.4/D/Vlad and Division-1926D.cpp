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
    // the group can have one number or max of 2 numbers 
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
        map<ll, int>freq;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int ans = n;
        ll p = (1LL << 31) - 1; //(2^31 -1)  31 bits (all ones)
        for (int i = 0; i < n; i++) {
            if (freq[a[i]] != 0) {
                ll inv = p & (~a[i]); //cuts everything to only 31 bits, doing that to search about the number we can add with a[i] as a group (with all bits differs than the bits of the current number (a[i]))
                if (freq[inv] != 0) {
                    ans--;
                    freq[a[i]]--;
                    freq[inv]--;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
