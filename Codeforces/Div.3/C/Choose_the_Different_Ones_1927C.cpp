#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <array>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <functional>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <list>
#define ll  long long
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        map<int,int>a, b;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x!=0 && x <= k) {
                a[x] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (x!=0 &&x<=k) {
                b[x] = 1;
            }
        }
        vector<int>check(k + 1);
        int cntrA = (k / 2), cntrB = (k / 2);
        for (auto tmp : a) {
            if (b[tmp.first] != 1) {
                cntrA--;
                check[tmp.first] = 1;
            }
        }
    
         for (auto tmp : b) {
            if (a[tmp.first] != 1) {
                cntrB--;
                check[tmp.first] = 1;
            }
         }
       
         if (cntrA < 0 ||cntrB<0) {
             cout << "NO\n";
         }
         else if (cntrA == 0 && cntrB == 0) {
             cout << "YES\n";
         }
         else {  //either rest of nums isnt there so NO or both a and b have rest of numbers so YES 
             for (int i = 1; i <= k; i++) {
                 if (check[i] == 0) {
                     if (a[i] == 1) //a or b (doesnt matter)
                     {
                         check[i] = 1;
                     }
                 }
             }
             int flag = 0;
             for (int i = 1; i <= k; i++) {
                 if (check[i] == 0) {
                     flag = 1;
                     break;
                 }
             }
             if (flag) {
                 cout << "NO\n";
             }
             else {
                 cout << "YES\n";
             }
         }
    }
    return 0;
}
