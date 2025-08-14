#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int main() {  
    int t,n,h;
    cin >> t;
    while (t--) {
        cin >> h>>n;
        vector<int>a(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        long long  l = 1, r = 5e10;
        while (l < r) {
            long long md = l + (r - l) / 2;
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                long long tmp = (md+(c[i]-1)) / c[i];  //ceiling
                if(sum<h)   //to avoid overflow -_-
                sum += (tmp * a[i]);
            }
            if (sum >= h)
            {
                r = md;
            }
            else {
                l = md + 1;
            }
        }
        cout << r << "\n";
    }
    return 0;
}
