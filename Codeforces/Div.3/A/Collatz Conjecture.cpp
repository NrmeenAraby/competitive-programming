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
        int k,x;
        cin >> k>>x;
        int ans=x;
        while (k--) {
                ans *=  2;
           
        }
        cout << ans << "\n";

    }  

    return 0;
}
