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
        int n;
        cin >> n;
        int x,tmp=n+1;
        for (int i = 0; i < n; i++) { 
            cin >> x;
            cout << tmp - x<<" ";
        }
        cout << "\n";
    }  

    return 0;
}
