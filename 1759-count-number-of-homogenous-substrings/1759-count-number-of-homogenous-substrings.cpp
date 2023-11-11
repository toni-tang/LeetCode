class Solution {
public:
    int countHomogenous(string s) {
        int res = 0, curr = 0, count = 0, mod = 1e9 + 7;
        for (int c : s) {
            count = (c == curr) ? count + 1 : 1;
            curr = c;
            res = (res + count) % mod;
        }
        return res;
    }
};