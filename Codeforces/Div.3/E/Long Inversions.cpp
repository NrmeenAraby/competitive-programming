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
        string s;
        cin >> n >> s;
        int ans = 0;
        for (int k = n; k >=1; k--) {
            vector<int>flippingMemo(n+1, 0);
            int curr = 0,flag=0;
            for (int i = 0; i < n; i++) {
                curr ^= flippingMemo[i];
                char bit=s[i];
                if (curr)//we should flip the current bit(as a prev flipping operation affected this bit)
                {
                    if (s[i] == '0')
                        bit = '1';
                    else
                        bit = '0';
                }
                if (bit == '0') { //we should do a flip operation by k size
                    if (i + k-1 >n-1 ) { //so this k cant be used
                        flag = 1;
                        break;
                    }
                    curr ^= 1;
                    flippingMemo[i + k] ^= 1;
                }
            }
            if (flag == 0)
            {
                ans = k;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
