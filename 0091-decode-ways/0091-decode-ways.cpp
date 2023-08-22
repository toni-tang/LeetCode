class Solution {
public:
// Recursion
//     int numDecodings(string s) {
//         return s.size() == 0 ? 0 : decode(s, 0);
//     }
    
//     int decode(string &s, int i) {
//         if(i == s.size()) return 1;
//         if(s[i] == '0') return 0;
//         int res = decode(s, i+1);
//         if(i < s.size()-1 && ( s[i] == '1' || ( s[i] == '2' && s[i+1] < '7' ) )) res += decode(s, i+2);
//         return res;
//     }
    
    
// Memoization
//     int numDecodings(string s) {
//         vector<int> mem(s.size()+1, -1);
//         mem[s.size()] = 1;
//         return s.size() == 0 ? 0 : decode(s, 0, mem);
//     }
    
//     int decode(string &s, int i, vector<int>& mem) {
//         if(mem[i] > -1) return mem[i];
//         if(s[i] == '0') return mem[i] = 0;
//         int res = decode(s, i+1, mem);
//         if(i < s.size()-1 && ( s[i] == '1' || ( s[i] == '2' && s[i+1] < '7' ) )) res += decode(s, i+2, mem);
//         return mem[i] = res;
//     }

    
// Tabulation
//     int numDecodings(string s) {
//         int n = s.size();
        
//         vector<int> dp(n+1);
//         dp[n] = 1;
    
//         for(int i = n-1; i >= 0; i--) {
//             if(s[i] == '0') dp[i] = 0;
//             else {
//                 dp[i] = dp[i+1];
//                 if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) dp[i] += dp[i+2];
//             }
//         }
        
//         return s.empty() ? 0 : dp[0];
//     }

// Optimization
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        
        for(int i = n-1; i >= 0; i--) {
            int cur = (s[i] == '0') ? 0 : p;
            if(i < n-1 && (s[i]=='1'|| s[i]=='2' && s[i+1]<'7')) cur += pp;
            pp = p;
            p = cur;
        }
        
        return s.empty()? 0 : p;   
    }
};