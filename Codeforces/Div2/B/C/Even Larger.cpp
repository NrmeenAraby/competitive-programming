#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>v(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        long long ans = 0;
        for (int i = 2; i <= n; i+=2) {
            long long tmp = v[i - 1];
            if (i + 1 <= n) {
                tmp += v[i + 1];
            }
           
            //cout << "Tmp " << tmp << "\n";

            if (tmp > v[i]) {
                tmp -= v[i];
                ans += tmp;


                //cout << "ans" << ans << "\n";
                if (v[i - 1] > v[i]) {
                    tmp -= (v[i - 1] - v[i]);
                    // v[i - 1] = v[i];  //no need for this line, wont affect anything
                }
                if (i + 1 <= n) {
                    if (v[i + 1] >= tmp) {
                        v[i + 1] -= tmp;
                    }
                    else {
                        v[i + 1] = 0;  //to avoid  -ve as the req need 
                    }
                }
            }
           
        }
        cout << ans << "\n";

    }
    return 0;
}
