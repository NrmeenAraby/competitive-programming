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
const int MAX = 2e5+5;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n>>m;
        string x, s;
        cin >> x >> s;
        int cntr = 0;
        string tmp;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int idx = 0;
            cntr = 0;
            tmp = x;
            while (true) {
                if (idx==s.size()) {
                    flag = 1;       // so we did it
                    break;
                }
                if (j == tmp.size()) {
                    tmp.append(tmp);
                    cntr++;
                }
               
                if( tmp[j] != s[idx]) {
                    break;  //go and try another i  (in case i still < n)
                }
                j++;
                idx++;
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << cntr << "\n";
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
