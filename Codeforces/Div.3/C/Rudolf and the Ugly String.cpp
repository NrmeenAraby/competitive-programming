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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
                s[i] = '*';
                ans++;
            }
        }
        for (int i = n - 1; i >= 2; i--) {
            if (s[i]=='p'&&s[i-1]=='a'&&s[i-2]=='m') {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
