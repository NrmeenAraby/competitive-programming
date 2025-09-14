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
        int x, n;
        cin >> x >> n;
        if (n % 2 == 0)
            cout << 0 << "\n";
        else
            cout << x << "\n";
    }
    return 0;
}

