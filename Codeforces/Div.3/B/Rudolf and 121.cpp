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
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int flag = 0;
        for (int i = 0; i < n-2; i++) {
            if (a[i] < 0)
                flag = 1;

            if (a[i] > 0) {
                a[i + 1] -= 2 * a[i];
                a[i + 2] -= a[i];
                a[i] = 0;
            }
        }
        if (a[n - 2] != 0 || a[n - 1] != 0)  //(either >0 or <0)as they didnt get checked inside the loop 
            flag = 1;

        if (flag)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}
