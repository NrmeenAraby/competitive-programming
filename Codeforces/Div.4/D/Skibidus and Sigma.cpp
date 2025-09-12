#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MOD = 32768;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, vector<int>>mp;
        int x;
        long long sum ;
        vector<pair<int,int>>v;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                cin >> x;
                mp[i].push_back(x);
                sum += x;
            }
            v.push_back({ sum ,i});
        }
        sort(v.begin(), v.end(),greater<>());
        vector<long long>sufx(n * m);
        int cntr = 0;
        for (int i = 0; i < v.size(); i++) {
            int arrIdx = v[i].second;
            for (int it : mp[arrIdx]) {
                if (cntr == 0) {
                    sufx[cntr] = it;
                }
                else {
                    sufx[cntr] = sufx[cntr - 1] + it;
                }
                cntr++;
            }
        }
        long long ans=0;
        for (int i = 0; i < m * n; i++) {
            ans += sufx[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
 
