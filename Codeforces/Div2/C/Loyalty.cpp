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
const long long MAX = 1e9;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        deque<long long>dq(n);
        for (int i = 0; i < n; i++) {
            cin >> dq[i];
        }
        sort(dq.begin(), dq.end());
        vector<int>ans;
        long long sum = 0, bonus = 0, lvl = 0;
        while (!dq.empty()) {
            long long tmp = dq.back();
            if ((sum + tmp) / x > lvl) {
                ans.push_back(tmp);
                lvl = (sum + tmp) / x;
                dq.pop_back();
                bonus += tmp;
            }
            else {
                tmp = dq.front();
                ans.push_back(tmp);
                dq.pop_front();
            }
            sum += tmp;
        }
        cout << bonus << "\n";
        for (auto p : ans) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}
