class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        
        int ptr = n-1;
        while(ptr >= 0 && s[ptr] == ' ') ptr--; /* Skip the trailing whitespaces */
        
        int len = 0;
        while(ptr >= 0 && s[ptr--] != ' ') len++; /* Counting the letters in the last word */
        return len;
    }
};