#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;
        vector<vector<char>>ans(n, vector<char>(n));
        if (k == (n * n) - 1)
        {
            cout << "No\n";
        }
        else{
            int flag = 0;
            int tmpi=n, tmpj=n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (k) {
                        ans[i][j] = 'U';
                        k--;
                    }
                    else {
                        tmpi = i, tmpj = j;
                        flag = 1;
                        break;
                    }
                   
                }
                if (flag)
                    break;
            }
            if (tmpj == n - 1) {
                ans[tmpi][tmpj] = 'D';
            }
            else if (tmpj<n-1 ){
                ans[tmpi][tmpj] = 'R';
                for (int j = tmpj+1; j < n; j++) {
                    ans[tmpi][j] = 'L';
                }
            }
            for (int i = tmpi+1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == 0) {
                        ans[i][j] = 'R';
                    }
                    else {
                        ans[i][j] = 'L';
                    }
                }
            }
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }
       
      
    }
    return 0;
}
