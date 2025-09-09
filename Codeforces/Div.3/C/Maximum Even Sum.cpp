#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MOD = 32768;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long ans;
        if (b % 2) {
            ans = (a * b) + 1;
        }
        else {
            long long tmp = b / 2;
            ans = (a * tmp) + (b / tmp);
        }
        if (ans % 2) {
            cout << -1 << "\n";
        }
        else
            cout << ans << "\n";
    }

    return 0;
}
