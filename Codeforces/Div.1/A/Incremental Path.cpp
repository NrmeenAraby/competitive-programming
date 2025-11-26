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
using namespace std;
const long long MAX = 1e9;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        map<int, int>black;
        int a;
        for (int i = 0; i < m; i++) {
            cin >> a;
            black[a] = 1;
        }
        int lstStep = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                lstStep ++ ;
                black[lstStep] = 1;
            }
            else {
                lstStep++;
                while (black[lstStep] == 1) {
                    lstStep++;
                }
                black[lstStep] = 1;
                lstStep++;
                while (black[lstStep] == 1) {
                    lstStep++;
                }
            }
        }
        vector<int>ans;
        for(auto b:black){
            if (b.second == 1) {
                ans.push_back(b.first);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
