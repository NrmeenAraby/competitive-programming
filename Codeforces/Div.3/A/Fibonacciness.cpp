#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int>v(4);
        for (int i = 0; i < 4; i++) {
            cin >> v[i];
        }
        int try1 = 1, try2 = 1;
        int t1 = v[0] + v[1];
        int t2 = v[2] - v[1];
        if (v[2] == t1 + v[1])try1++;
        if (v[3] == v[2] + t1)try1++;

        if (t2 == v[0]+v[1])try2++;
        if (v[3] == v[2] + t2)try2++;

        cout << max(try1, try2)<<"\n";
        
        
    }
    return 0;
}
