#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int main() {  
    int t,n;
    cin >> t;
    while (t--) {
        cin >>n;
        vector<int>a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int ans = a[n-1];
        for (int i = 0; i < n-1; i++) {
            if (a[i] > b[i + 1]) {
                ans += a[i] - b[i + 1];
          }
        }
        cout << ans << "\n";
    }
    return 0;
}
