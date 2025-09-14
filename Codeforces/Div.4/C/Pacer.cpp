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
        int n, m;
        cin >> n >> m;
        int ans = m;
        int even = 0, odd = 1;
        int a, b;
        while (n--) {
            cin >> a >> b;
            if (a % 2 == 0) {
                if (b != even) {
                    swap(even, odd);
                    ans--;
                }
            }
            else {
                if (b != odd) {
                    swap(even, odd);
                    ans--;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

