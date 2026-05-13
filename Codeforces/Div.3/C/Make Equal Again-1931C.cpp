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
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int cntrl = 1, cntrr = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] == v[i-1]) {
                cntrl++;
            }
            else
            {
                break;
            }
        }
        for (int i = n-2; i >=0; i--) {
            if (v[i] == v[i + 1]) {
                cntrr++;
            }
            else
            {
                break;
            }
        }
        int ans = 0;
        if (cntrl==n) {
             ans = 0;        
        }
        else if (v[0] == v[n - 1]) {
            ans = n-(cntrr+cntrl);
        }
        else if (cntrl>cntrr){
            ans = n - cntrl;
        }
        else {
            ans = n - cntrr;
        }
        cout << ans << endl;
    }
    
    return 0;
}
