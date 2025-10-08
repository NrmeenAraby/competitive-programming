#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if (n <= 2) {
            cout << -1 << "\n";
        }
        else {
            sort(v.begin(), v.end());
            int half = n / 2;
            int afterHalf =  half + 1;
            long long limit = v[afterHalf-1];

            long long l = 0, r = 1e13;
            long long x;
            while (l <= r) {
                long long md = l + (r - l) / 2;
                long long  tmpSum = sum + md;
                //long long halfAvg = (tmpSum / n) / 2;
           
                if (tmpSum > limit*2ll*n) {
                    x = md;
                    r = md - 1;
                }
                else {
                    l = md + 1;
                }
            }
            cout << x << "\n";
        }
    }
    return 0;
}
