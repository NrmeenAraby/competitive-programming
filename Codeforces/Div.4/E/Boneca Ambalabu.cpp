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
bool isMnwara(int num,int bit) {
    return num & (1 << bit);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int>bitsMembers; //num of numbers elly 3ndhom el bit de mnwara (ya3ny mthlan fe 3 arqam mnwar 3ndhom bit 1 w mthlan 4 arqam mnwar 3ndhom bit 2 ...)
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 32; bit++) {
                if (isMnwara(a[i], bit)) {
                    bitsMembers[bit]++;
                }
                
            }
        }
        long long sum,mx=0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (isMnwara(a[i], bit)) {
                    sum += 1ll*(n - bitsMembers[bit]) * pow(2, bit);
                }
                else {
                    sum += 1ll * (bitsMembers[bit]) * pow(2, bit);
                }
            }
            mx = max(mx, sum);
        }
        cout << mx << "\n";

    }
    return 0;
}
