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
        int n,q;
        cin >> n>>q;
        set<pair<int, int>>st;
        vector<int>score(n + 1,0);
        for (int i = 1; i <= n; i++) {
            st.insert({ 0, i });
        }
        int x, p;
        int team = 1,event=0;  //INTIAL WINNRE IS team 1
        for (int i = 1; i <= q; i++) {
            cin >> x >> p;
            st.erase({ -score[x],x });
            score[x] += p;
            st.insert({ -score[x],x });

            int currentWinner = st.begin()->second;

            if (currentWinner != team) {
                    team = currentWinner;
                    event = i;
            }
            
        }
        if (event == 0)
        {
            cout << 0 << "\n";
        }
        else {
            cout << event << endl;
        }
    }
    return 0;
}
