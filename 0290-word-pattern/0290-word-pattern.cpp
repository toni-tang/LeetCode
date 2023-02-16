class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, int> mp2;
        stringstream ss(s);
        string word;
        int count = 0;
        
        for(int i = 0; i < pattern.length(); i++) {
            ss >> word;
            count++;
            
            if(mp.find(pattern[i]) == mp.end())
            {
                mp[pattern[i]] = word;
                mp2[word]++;
            }
            
            if(mp2[word] > 1) return false;
            if(mp.at(pattern[i]) != word) return false;
        }
        
        while(ss >> word)
        {
            count++;
        }
        
        if(count != pattern.length()) return false;
        
        return true;
    }
};