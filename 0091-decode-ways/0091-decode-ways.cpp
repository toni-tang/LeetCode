class Solution {
public:
// Recursive:
//     int numDecodings(string s) {
//         return decode(s, 0);
//     }

//     int decode(string s, int i) {
//         if(i == s.length()) return 1;
//         if(s[i] == '0') return 0;
//         int res = decode(s, i+1);
//         if(i < s.length()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) res += decode(s, i+2);
//         return res;
//     }
    
// Memoization: 
//     int numDecodings(string s) {
//         vector<int> dp(s.length()+1, -1);
//         dp[s.size()] = 1;
//         return decode(s, 0, dp);
//     }

//     int decode(string s, int i, vector<int>& dp) {
//         if(dp[i] > -1) return dp[i];
//         if(s[i] == '0') return dp[i] = 0;
//         int res = decode(s, i+1, dp);
//         if(i < s.length()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) res += decode(s, i+2, dp);
//         return dp[i] = res;
//     }
    
// Tabulation
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n+1, 0);
//         dp[n] = 1;
        
//         for(int i = n-1; i >= 0; i--) {
//             if(s[i] == '0') dp[i] = 0;
//             else {
//                 dp[i] = dp[i+1];
//                 if(i < s.length()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) dp[i] += dp[i+2];
//             }
//         }
        
//         return dp[0];
//     }
    
// Optimizied
    int numDecodings(string s) {
        int n = s.size();
        
        int curr, pp, p = 1;
        for(int i = n-1; i >= 0; i--) {
            curr = (s[i] == '0') ? 0 : p;
            if(i < s.length()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) curr += pp;
            pp = p;
            p = curr;
        }
        
        return curr;
    }
};
