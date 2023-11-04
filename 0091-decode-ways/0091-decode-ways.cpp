class Solution {
public:
// Recursive:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        dp[s.size()] = 1;
        return decode(s, 0, dp);
    }

    int decode(string s, int i, vector<int>& dp) {
        if(dp[i] > -1) return dp[i];
        if(s[i] == '0') return dp[i] = 0;
        int res = decode(s, i+1, dp);
        if(i < s.length()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))) res += decode(s, i+2, dp);
        return dp[i] = res;
    }
};