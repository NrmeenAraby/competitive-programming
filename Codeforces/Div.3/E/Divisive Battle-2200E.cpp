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
const int MAX = 3e5 + 5;
const int MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
vector<pair<int, int>>prime_factors;
void factorize(int n) {
    for (int i = 2; i * i <= n; i++) {
        int power = 0;
        while (n % i == 0) {
            power++;
            n /= i;
        }
        if (power) {
            prime_factors.push_back({ i,power });
        }
    }
    if (n != 1) {
        prime_factors.push_back({ n,1 });
    }
}

int main() {
    /*alice can win if she finds from its first move a number with at least two distinct prime factors so she will put the larger first and then the smaller,
    and with that she is the winner whatever happens*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int flag = 0,prev=a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < prev) {
                flag = 1;
                break;
            }
            else {
                prev = a[i];
            }
        }
        if (!flag) {
            cout << "Bob\n";
        }
        else {
            flag = 0;
            vector<int>tmp;
            for (int i = 0; i < n; i++) {
                prime_factors.clear();
                factorize(a[i]);
                if (prime_factors.size() >= 2) { //2 distinct prime factors or more
                    flag = 1;
                    break;
                }
                else {
                    if (a[i] == 1)
                    {
                        tmp.push_back(1);
                    }
                    else {
                        tmp.push_back(prime_factors[0].first);// kda kda mafeesh 8er prime factor wa7d bs
                    }
                }
            }
            if (flag) {
                cout << "Alice\n";
            }
            else {
                flag = 0;
                prev = tmp[0];
                for (int i = 1; i < tmp.size(); i++) {
                    if (tmp[i] < prev) {
                        flag = 1;
                        break;
                    }
                    else {
                        prev = tmp[i];
                    }
                }
                if (flag) {
                    cout << "Alice\n";
                }
                else {
                    cout << "Bob\n";

                }
            }
        }
    }
    return 0;
}
