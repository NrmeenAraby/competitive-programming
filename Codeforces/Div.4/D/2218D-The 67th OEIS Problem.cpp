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
const int INF =1e9;
const int MOD = 1e9 + 7;
vector<bool>isPrime(MAX+1, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();
    vector<int>primes;
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>a(n);
        a[0] = primes[0];
        for (int i = 1; i < n; i++) {
            a[i] = 1ll*primes[i - 1] * primes[i];
        }
        for (auto num : a) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}
