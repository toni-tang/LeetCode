class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        
        for(auto& c : s) {
            if(isVowel(c)) {
                vowels.push_back(c);
            }
        }
        
        sort(vowels.begin(), vowels.end());
        
        for(int i = 0, j = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }
        
        return s;
    }
    
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'A' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }
};