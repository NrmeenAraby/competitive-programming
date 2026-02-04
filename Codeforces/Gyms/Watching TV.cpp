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
        int n;
        cin >> n;
        string s;
        int f;
        map<int, int>mp;
        while (n--) {
            cin >> s >> f;
            mp[f]++;
        }
        int mx = 0,freqMx=-1;
        for (auto &p : mp) {
            int freq = p.first,cntr=p.second;
            if (p.second > mx) {
                mx = p.second;
                freqMx = freq;
            }
            else if (p.second == mx) {
                if (freq < freqMx)
                    freqMx = freq;
            }

        }
        cout << freqMx << endl;
    }
    return 0;
}
