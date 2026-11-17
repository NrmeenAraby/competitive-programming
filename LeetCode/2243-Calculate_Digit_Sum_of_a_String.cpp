class Solution {
public:
    string digitSum(string s, int k) {
        while (true) {
            int sz = s.size();
            if (sz <= k)
                return s;
            string tmp = "";
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                sum += s[i] - '0';
                if ((i + 1) % k == 0 || i==sz-1) {
                    tmp+=to_string(sum);
                    sum = 0;
                }
            }
            s = tmp;
        }
    }
};
