#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
/*
   1-Any even number > 2 is composite.
   2-When we add two numbers of the same parity we get an even number(composite).
   3- so, here we should find an odd and an even number that sum up to composite
    and we found that can't happen if n < 5 ( if n>5 we can find that 4+5=9 which is composite).
    so we can put even nums together and then put 4 and 5 then put the odd nums.
   (... even,4,5,odd,...)
*/
int main() {  
    int t,n;
    cin >> t;
    while (t--) {
        cin >>n ;
        if (n < 5) {
            cout << -1;
        }
        else {
            for(int i=n;i>=2;i--){
                if (i % 2 == 0 && i != 4) {
                    cout << i << " ";
                }
            }
            cout << 4 << " " << 5 << " ";
            for (int i = 1; i <= n; i++) {
                if (i % 2 != 0 && i != 5)
                    cout << i << " ";
            }

        }
        cout << "\n";
    }
    return 0;
}
