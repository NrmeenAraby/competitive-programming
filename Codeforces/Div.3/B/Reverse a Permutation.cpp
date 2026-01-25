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
        int n;
        cin >> n;
        vector<int>v(n);
        int l = n, r = n,ok=n+1,flag=0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i]==n-i && !flag){
                ok = n - i;
            }
            else if(!flag){
                l = i;
                flag = 1;
            }
            if (flag && v[i] == ok - 1) {
                r = i;
            }
        }
        vector<int>rev;
        for (int i = l; i <= r; i++) {
            if(i!=n)
             rev.push_back(v[i]);
        }
        reverse(rev.begin(), rev.end());
        for (int i = 0; i < l; i++) {
            
            cout << v[i] << " ";
        }
        for (int i = 0; i < rev.size(); i++) {
           
            cout << rev[i] << " ";
        }
        for (int i = r + 1; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
