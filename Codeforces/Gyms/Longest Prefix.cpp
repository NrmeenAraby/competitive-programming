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
    int t = 1;
    cin >> t;
    while (t--) {
        string a,b;
        cin >> a >> b;
        map<char, int>mp;
        for (int i = 0; i < b.size(); i++) {
            mp[b[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (mp[a[i]]) {
                ans++;
                mp[a[i]]--;
            }
            else
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}
