#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
int main() {
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int>a(n);
        map<int, int>freq;
        int idx = 0;
        vector<int>b(n);
        unordered_set<int>curr;
        unordered_set<int>nxt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (freq[a[i]] == 0) {
                b[idx] = a[i];
                idx++;
                curr.insert(a[i]);
            }
            freq[a[i]] = 1;
        }
        int nxtcntr = 2;
        for (int i = idx; i < n; i++) {
            if (curr.empty()) {
                curr.swap(nxt);
                nxtcntr++;
            }


            if (freq[a[i]] < nxtcntr) {
                b[i] = a[i];
                freq[b[i]]++;
                curr.erase(a[i]);
                nxt.insert(a[i]);
               
            }
            else {
                b[i] = *curr.begin();
                freq[b[i]]++;
                curr.erase(b[i]);
                nxt.insert(b[i]);
               
            }
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
