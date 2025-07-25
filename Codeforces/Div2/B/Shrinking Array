#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int>v(n);
        int prv,flag=0;
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i != 0) {
                if (v[i] == prv || abs(v[i] - prv) == 1) {
                    flag = 1;
                }
            }
            prv= v[i];
        }
        if (flag) {
            cout << 0 << "\n";
        }
        else if (n == 2) {
            cout << -1 << "\n";
        }
        else {
            int hi = 0;
            int prvDiff = v[1] - v[0];
            for (int i = 2; i < n; i++) {
                int currDiff = v[i] - v[i - 1];
                if ((currDiff / abs(currDiff)) != (prvDiff / abs(prvDiff))) { //make sure m4 kolo increasing aw decreasing(not sorted)
                    cout << 1 << "\n";
                    hi = 1;
                    break;
                }
                prvDiff = currDiff;
            }
            if(hi==0)
             cout << -1 << "\n";
        }
            
       
        
    }
    return 0;
}
