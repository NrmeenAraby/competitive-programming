#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int main() {  
    int t,n,m,k;
    cin >> t;
    while (t--) {
        cin >>n >> m >> k ;
        vector<int>a(m );
        map<int, int>easy;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        int x;
        for (int i = 0; i < k; i++) {
            cin >> x;
            easy[x] = 1;
        }
        if (k == n)
        {
            for (int i = 0; i < m; i++) {
                cout << 1;
            }
           
        }
        else if (k < n - 1) {
            for (int i = 0; i < m; i++) {
                cout << 0;
            }
         
        }
        else {
            for (int i = 0; i < m; i++) {
                if (easy[a[i]] == 1) //so there is a question that in the list and mono don't know(chance of absence of the question he dont know is missed)
                {
                    cout << 0;
                }
                else
                {
                    cout << 1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
