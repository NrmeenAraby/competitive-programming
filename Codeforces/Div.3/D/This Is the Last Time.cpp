#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int t,n,k ;
    cin >> t;
    while (t--) {
        cin >> n>>k;
        vector<tuple<int, int, int>> v(n);
        int a, b, c;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            v[i]=make_tuple(a,b,c);     
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            if (get<0>(a) != get<0>(b))
                return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b))
                return get<1>(a) < get<1>(b);
            return get<2>(a) > get<2>(b);  
            });
         
        for (auto& c : v) {
            if (k >= get<0>(c) && k <= get<1>(c)) {
                if (get<2>(c) > k)
                    k = get<2>(c);
            }

        }
        cout << k << "\n";

    }
    return 0;
}
