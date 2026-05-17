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
        int n;
        string s;
        cin >> n >> s;
        int start = -1, e = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B' ) {
                if (start == -1) {
                    start = i;
                }
                else {
                    e = i;
                }
            }
        }
        if (start == -1)
            cout << 0 << endl;
        else if (e == -1) {
            cout << 1 << endl;
        }
        else {
            cout << e - start + 1 << endl;
        }
    }
    
    return 0;
}
