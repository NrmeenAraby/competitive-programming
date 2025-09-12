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
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int b;
        cin >> b;
        if (b - a[0] < a[0])
            a[0] = b - a[0];
        int tmp,flag=0;
        for (int i = 1; i < n; i++) {
            tmp = b - a[i];
           
            if (tmp >=a[i-1]) {
                if ( tmp < a[i]) {
                    a[i] = tmp;
                }
                else if (a[i] < a[i - 1]) {
                    a[i] = tmp;
                }
            }
            else if (a[i] < a[i - 1]) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
 
