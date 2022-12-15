class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length()+1;
        int m = text2.length()+1;
        vector<vector<int>> res( n , vector<int> (m)); 
         
        for(int r = 1; r < text1.length() + 1; r++)
        {
           for(int c = 1; c < text2.length() + 1; c++)
           {
                if(text1[r-1] == text2[c-1])
                {
                    res[r][c] = 1 + res[r-1][c-1];
                }
                else
                {
                    res[r][c] = max(res[r-1][c], res[r][c-1]);
                }
           } 
        }
        
        return res[text1.length()][text2.length()];
    }
};