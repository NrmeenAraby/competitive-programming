#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t,n,k ;
    cin >> t;
    while (t--) {
        cin >> n>>k;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];     
        }
        int curr = v[k - 1];
        sort(v.begin(), v.end());
        int water = 1,flag=0;
        for (int i = 0; i< n; i++) {
            if (v[i] > curr) {
                int tmp = v[i] - curr;
                water += tmp;
                if (water > curr + 1) {
                    flag = 1;
                    break;
                }
                else {
                    curr = v[i];
                }
            }
                
        }
        if (flag) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
     
    }
    return 0;
}
