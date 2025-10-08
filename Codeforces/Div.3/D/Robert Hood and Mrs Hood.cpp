#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n,d,k;
        cin >> n>>d>>k;
        vector<pair<int, int>>startEnd(n + 1, {0,0});
        int l, r;
        for (int i = 0; i < k; i++) {
            cin >> l >> r;
            startEnd[l].first++;  //job starts 
            startEnd[r].second++;  //job ends
        }
        int right = 1,jobCounter=0,mx=0,mn=1e9,Bro=0,Mom=0;
        for (int left = 1; left <= n-d+1; left++) {
            while (right - left < d && right <= n) {
                jobCounter += startEnd[right].first;
                right++;
            }
            if (jobCounter > mx) {
                mx = jobCounter;
                Bro = left;
            }
            if (jobCounter < mn) {
                mn = jobCounter;
                Mom = left;
            }
            jobCounter -= startEnd[left].second;
        }
        cout << Bro << " " << Mom << "\n";
        
    }
    return 0;
}
