#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int dp[MAX];
int m;
bool solve(int num) {
    if (num == m)
        return true; //found
    if (num < m )
        return false;
    if (num%3!=0)
        return false;

    return   solve(num / 3) || solve((num / 3) * 2);
  
}
int main() {
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n >> m;
     
        solve(n);
        if (solve(n))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
