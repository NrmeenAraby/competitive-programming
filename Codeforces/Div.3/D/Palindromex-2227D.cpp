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
const int MAX = 2e5 + 5;
const int MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int n;
vector<int>v;
int max_mex =1;
void around_each_zero(int i, int j) {
    if (i >= 0 && j < 2 * n) {
        int flag = 0;
        while (i >= 0 && j < 2 * n) {
            if (v[i] != v[j]) {
                i++;
                j--;
                break;
            }
            flag = 1;//some elements found
            i--;
            j++;
            if (i < 0 || j>=(2 * n)) {
                i++, j--;
                break;
            }
        }
        if (flag) {
            map<int, int>mp;
            for (int k = i; k <= j; k++) {
                mp[v[k]] = 1;
            }
            int mex = 1;
            while (mp.count(mex)) {
                mex++;
            }
            max_mex = max(max_mex, mex);
        }
    }
}
int main() {
    /* Any palindrome without 0 has mex = 0
    Therefore, we only consider palindromes containing 0, whose mex is at least 1.*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {      
        cin>> n;
        max_mex = 1;
        v.clear();
        v.resize(2 * n);
        int zero1=-1, zero2=-1;
        for (int i = 0; i < 2*n; i++) {
            cin >> v[i];
            if (v[i] == 0) {
                if (zero1 == -1) {
                    zero1 = i;
                }
                else {
                    zero2 = i;
                }
            }
        }
        around_each_zero(zero1 - 1, zero1 + 1);
        around_each_zero(zero2 - 1, zero2 + 1);
        int i = zero1 + 1;
        int j = zero2 - 1;
        int flag = 0;
        while (i<=j) {
            if (v[i] != v[j]) {
                flag = 1;
                break;
            }
            i++;
            j--;
        }
       // cout << "flag " << flag << endl;
        if (flag == 0)  { // it means that the in between is a palindrome subarray
            //check left of zero1 with right of zero2
            int expanded = 0;
            int i = zero1 - 1, j = zero2 + 1;
            if (i >= 0 && j < 2 * n) {
                while (i>=0 && j<2*n) {
                    if (v[i] != v[j]) {
                        i++;
                        j--;
                        break;
                    }
                    expanded = 1;//some elements found
                    i--;
                    j++;
                    if (i < 0 || j>=(2 * n)) {
                        i++, j--;
                        break;
                    }
                }   
            }
            int st = zero1 + 1, end = zero2 - 1;
            if (expanded) {
                st = i, end = j;
            }
            map<int, int>mp;
            for (int k = st; k <= end; k++) {
                mp[v[k]] = 1;
            }
            int mex = 1;
            while (mp.count(mex)) {
                mex++;
            }
            max_mex = max(max_mex, mex);
        }
        cout << max_mex << endl;
    }
    return 0;
} 
