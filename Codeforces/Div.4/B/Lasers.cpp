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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
        }
        
        for (int i = 0; i < m; i++) {
            cin >> a;
        }
      
        cout << n + m << "\n";
    }
    return 0;
}

