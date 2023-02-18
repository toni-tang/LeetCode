class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length() < 2) return "";
        
        for(int i = 0; i < palindrome.length(); i++) {
            if(i == palindrome.length()/2 && palindrome.length()-1 != palindrome.length()/2);
            else if(i == palindrome.length()-1 && palindrome[i] == 'a')
            {
                palindrome[i] = (int)palindrome[i] + 1;
                return palindrome;
            }
            else if(palindrome[i] != 'a') 
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        return palindrome;
    }
};