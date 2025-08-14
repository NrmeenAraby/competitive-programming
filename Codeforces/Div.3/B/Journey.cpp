#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int main() {  
    int t,n,a,b,c;
    cin >> t;
    while (t--) {
        cin >>n >> a >> b >> c;
        long long sum = a + b + c;
        long long ans = (n / sum) * 3;
        long long rem = n % sum;
        if (rem > 0)
        {
            rem -= a;
            ans++;
        }
        if (rem > 0)
        {
            rem -= b;
            ans++;
        }
        if (rem > 0)
        {
            rem -= c;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
