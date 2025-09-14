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
        int n;
        cin >> n;
        vector<int>odd;
        long long sum = 0;
        int a;
        for (int i = 0; i < n;i++) {
            cin >> a;
            if (a % 2 == 0) {
                sum += a;
            }
            else {
                odd.push_back(a);
            }
        }
        if (odd.empty()) {
            cout << 0 << "\n";
        }
        else {
            sort(odd.begin(), odd.end(),greater<>());
            int idx = odd.size();
            if (idx % 2 == 1) {
                idx = (idx/2)+1;
            }
            else {
                idx = idx / 2;
            }
            for (int i = 0; i < idx; i++) {
                sum += odd[i];
            }
            cout << sum << "\n";
        }
    }
    return 0;
}

