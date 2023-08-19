class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int first = 0, second = 0;
        while(first < str1.length() && second < str2.length()) {
            if(str1[first] == str2[second] || str1[first] + 1 == str2[second] || str1[first] == 'z' && str2[second] == 'a') {
                second++;
            } 
            first++;
        }
    
        return second >= str2.length() ? true : false;
    }
};