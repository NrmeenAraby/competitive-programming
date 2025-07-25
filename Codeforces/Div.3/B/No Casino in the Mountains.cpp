#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t,n,k ;
    cin >> t;
    while (t--) {
        cin >> n>>k;
        int x;
        int cntr = 0,p=0,off=0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x == 0 && off==0) {
                cntr++;
            }
            else {
                cntr = 0;
                off = 0;
            }
            if (cntr==k) {
                p++;
                cntr = 0;
                off = 1;
            }
        }
        cout << p << "\n";

    }
    return 0;
}
