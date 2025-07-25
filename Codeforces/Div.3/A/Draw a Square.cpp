#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t, l,r,d,u;
    cin >> t;
    while (t--) {
        cin >> l >> r >> d >> u;
        if (l != r || l != d || l != u) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
    return 0;
}
