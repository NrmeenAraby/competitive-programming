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
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int half = (n + 1) / 2;
        int odd = 0;
        if (n % 2)
            odd = 1;
        vector<int>ans(n);
        for (int i = 0; i < half; i++) {
            int remPos = n  - ((i+1) * 2);
            int flag = 0;
            int limit = 0;
            if (i == 0)
                limit = 1; //to avoid leading 0
            for (int dig = 9; dig >= limit; dig--) {
                if (i == half - 1 && odd) {
                    if (s <=9) {
                        ans[i] = s;
                        s = 0;
                        flag = 1;
                    }
                    break;
                }
                else if (s - (2 * dig) >= 0 && s - (2 * dig) <= 9 * remPos) {
                    ans[i] = dig, ans[n - 1 - i] = dig;
                    s -= 2 * dig;
                    flag = 1;
                    break;
                }
               
            }
            if (flag == 0) {
                break;
            }

              
        }
        if (s!=0)
            cout << -1 ;
        else {
            for (auto num : ans) {
                cout << num;
            }
        }
        cout << endl;
    }
    return 0;
}
