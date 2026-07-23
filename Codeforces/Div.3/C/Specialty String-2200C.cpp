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
const int MAX = 3e5 + 5;
const int MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, vector<int>>mp;
        for (int i = 0; i < s.size(); i++) {
            if (!mp[s[i]].empty()) {
                int last = mp[s[i]].back();
                if (i - last == 1) {
                    mp[s[i]].pop_back();
                    s[i] = '*', s[last] = '*';
                }
                else  {
                    int flag = true;
                    for (int k = last + 1; k < i; k++) {
                        if (s[k] != '*')
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        mp[s[i]].pop_back();
                        s[i] = '*', s[last] = '*';
                    }
                    else {
                        mp[s[i]].push_back(i);
                    }
                }
            }
            else if (s[i] != '*') {
                mp[s[i]].push_back(i);
            }
        }
        int flag = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*')
            {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
         
    }
    return 0;
}
