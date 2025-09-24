#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        long long k,lx,rx,ly,ry;
        cin >> k >> lx >> rx >> ly >> ry;
     
        //say k = 2(smallest num possible), so 2^32>10^9, so it is okay to depend on k to break the loop(No TLE)    
        long long ans = 0,kPn=1;
        while(true) {
            if (kPn > 1e9)
                break;
            long long xmn = max(lx, (ly + kPn - 1) / kPn);
            long long xmx = min(rx, ry / kPn);

            if ( xmn<=xmx) {  //To avoid bad intervals, so No need to check xmn <=rx && xmx>=lx 
                ans += (xmx - xmn) + 1;
            }
            kPn *= k;
        }
        cout << ans << "\n";
    }
    return 0;
}
