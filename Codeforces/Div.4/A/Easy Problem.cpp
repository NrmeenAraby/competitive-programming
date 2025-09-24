#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int cntr = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (i + j == n) {
                        cntr++;
                    }
                }
            }
        
        cout << cntr << "\n";
    }
    return 0;
}
