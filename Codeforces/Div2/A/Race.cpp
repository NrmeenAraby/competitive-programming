#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t, a, x, y;
    cin >> t;
    while (t--) {
        cin >> a >> x >> y;
        int bf = (x + y) / 2;
        //int bc = (x + y + 1) / 2;
        if ((x>a && y>a) ||(a>x && a>y)) {
            cout << "Yes\n";
        }
        else {
            if (abs(bf - x) < abs(a - x) && abs(bf - y) < abs(a - y)) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }

    }
    return 0;
}
