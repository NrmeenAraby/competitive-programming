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
const long long MAX = 1e18;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n,c,d;
        cin >> n>>c>>d;
        vector<long long>v(n * n);
        map<long long, int>mp;
        long long mn = 1e9 + 5;
        for (int i = 0; i < n * n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
            mn = min(mn, v[i]);
        }
        vector<vector<long long>>s(n, vector<long long>(n));
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    s[i][j] = mn;
                }
                else if(j==0) {
                    s[i][j] = s[i - 1][j] + c;
                
                }
                else {
                    s[i][j] = s[i][j - 1] + d;

                }
                if (mp[s[i][j]] == 0) {
                    flag = 1;
                }
                else {
                    mp[s[i][j]]--;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (flag)
            cout << "No\n";
        else
            cout << "Yes\n";


    }
    return 0;
}
