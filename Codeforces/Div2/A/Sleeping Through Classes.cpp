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
#define ll  long long
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

int main() {
    int t=1;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;
        string s;
        cin >> s;
        int i = 0;
        int ans = 0,lstPos=-1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if(lstPos == -1 || (i - lstPos) > k)
                     ans++;
            }
            else {
                lstPos = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
