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
        string s;
        cin >> s;
        vector<int> last(26, -1),vis(26,-1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        char c1 = '*', c2 = '*';
        bool found = false;
        for (int i = 0; i < s.size(); i++) {
            for (char ch = 'a'; ch < s[i]; ch++) {
                if (last[ch - 'a'] > i&&vis[ch - 'a']==-1) {
                    c1 = s[i];
                    c2 = ch;
                    found = true;
                    break;
                }
               
            }
            vis[s[i] - 'a'] = 1;
            if (found)
                break;
        }
        if (found) {
            for (char &ch : s) {
                if (ch == c1) {
                    ch = c2;
                }
                else if (ch == c2) {
                    ch = c1;
                }
            }
        }
        cout << s << "\n";

    }
    return 0;
}
