#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t,x ;
    cin >> t;
    while (t--) {
        cin >> x;
        int mn = 9;
        while (x) {
            int t = x % 10;
            mn = min(mn, t);
            x /= 10;
        }
        cout << mn << endl;
    }
    return 0;
}
