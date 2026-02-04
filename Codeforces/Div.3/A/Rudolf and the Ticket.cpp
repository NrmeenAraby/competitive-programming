#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <numeric>
#include<queue>
#include<array>
#include<string>
#include <functional>
#include <iomanip>
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

#define ll  long long

int main() {
    int t;
    cin >> t;
    //cout << fixed << setprecision(10);
    while (t--) {
        int n, m,k;
        cin >> n >> m>>k;
        vector<int>b(n), c(m);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }

        sort(b.begin(), b.end());
        sort(c.begin(), c.end(), greater<>());
        int j = 0,sum=0;
        for (int i = 0; i < n; i++) {
            while (j<m && c[j]+b[i]>k){
                j++;
            }
            sum += (m - j);
        }
        cout << sum << "\n";
    }

    return 0;
}
