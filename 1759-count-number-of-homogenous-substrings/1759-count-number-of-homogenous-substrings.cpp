class Solution {
public:
    int countHomogenous(string s) {
        if(s.length() == 1) return 1;
        
        cout << s.length() << endl;
        
        int res = 0;
        char prev = s[0];
        int L = 0, R = 0;
        int mod = 1e9 + 7;
        for(; R < s.length(); R++) {
            if(prev != s[R]) {
                for(long long i = 1; i <= R - L; i++) {
                    res = (res + i) % mod;
                }
                L = R;
            }
            
            prev = s[R];
        }
        
        for(long long i = 1; i <= R - L; i++) {
            res = (res + i) % mod;
        }
        
        return res;
    }
};