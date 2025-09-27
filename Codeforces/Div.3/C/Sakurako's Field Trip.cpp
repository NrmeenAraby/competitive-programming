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
        vector<int>v(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int i = 2; i <= n; i++) {
            if (v[i] == v[i - 1] || v[n - i + 1] == v[n - i + 2]) {
                swap(v[i], v[n - i + 1]);   // not to swap v[i-1] with v[n-i+2] as it may affect the number before i-1 or the number after n-i+2, but with i and n-i+1 we know that it eithrt improve or not improve but, won't make it worse 
            }
        }
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (v[i] == v[i - 1]) {
                ans++;
            }
        }
        cout << ans<<"\n";
    }
    return 0;
}
