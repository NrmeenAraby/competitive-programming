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
    /*
        check if xor of a = xor of b >> so Tie.
        otherwise, check on MSB (if its xor on all elemnts of == its xor on all elements of b ) or no one can change bec of the two bits in a and b are same >>
         so this bit cannt help me to decide the winner .     
    */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>a(n), b(n);
        long long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x ^= a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            y  ^= b[i];
        }
        if (x == y) {
            cout << "Tie\n";
        }
        else {
           
            for (int bit = 30; bit >= 0; bit--) {
                int lst = -1;
                x = 0, y = 0;
                for (int i = 0; i < n; i++) {
                    x ^= (a[i] >> bit) & 1;
                    y ^= (b[i]>>bit) & 1;

                    if (((a[i] >> bit) & 1) != ((b[i] >> bit) & 1)) lst = i + 1;
                }
                if (lst == -1 || x == y) continue;
                if (lst % 2 == 0) {
                    cout << "Mai\n";
                }
                else {
                    cout << "Ajisai\n";
                }
                break;
            }
        }

    }
    return 0;
}
