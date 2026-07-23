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
    //Better late than never -_- 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin >> n>>x>>y;
        deque<int>l, r, m;
        x--, y--;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (i > x && i <= y) {
                m.push_back(num);
            }
            else if (i <= x)
            {
                l.push_back(num);
            }
            else {
                r.push_back(num);
            }
        }
        int mnM = *min_element(m.begin(), m.end());
        while ((!m.empty()) && m.front() != mnM) {
            m.push_back(m.front());
            m.pop_front();
        }
        int idx = -1;
        for (int i = 0; i < l.size(); i++) {
            if (l[i] > mnM) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            int cntr = 0;
            for (int i = l.size() - 1; i >= idx; i--) {
                r.push_front(l[i]);
                cntr++;
            }
            while (cntr) {
                l.pop_back();
                cntr--;
            }
        }
        else {
            while (true) {
                if (!r.empty() && r.front() < mnM) {
                    l.push_back(r.front());
                    r.pop_front();
                }
                else {
                    break;
                }
            }
        }
        while (!l.empty()) {
            cout << l.front()<<" ";
            l.pop_front();
        }
        while (!m.empty()) {
            cout << m.front() << " ";
            m.pop_front();
        }
        while (!r.empty()) {
            cout << r.front() << " ";
            r.pop_front();
        }
        cout << endl;
    }
    return 0;
}
