#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int main() {  
    int t,k;
    cin >> t;
    while (t--) {
        cin >>k ;
        map<int, int>mp;
        int x;
        for (int i = 0; i < k; i++) {
            cin >> x;
            mp[x]++;
        }
        int cntr = 1,r=k-2;
        int n, m;
        while (true) {
            if (r * cntr == (k - 2)) {
                if (cntr == r) {
                    if (mp[cntr] >= 2) {
                        n = cntr, m = r;
                        break;
                    }
                }
                else {
                    if (mp[cntr] && mp[r]) {
                        n = cntr, m = r;
                        break;
                    }
                }
            }
            cntr++;
            r = (k-2) / cntr;
           
        }
        cout << n << " " << m << "\n";
    }
    return 0;
}
