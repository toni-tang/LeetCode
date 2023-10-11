class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str;
        string res = "";
        while(ss >> str) {
            reverse(str.begin(), str.end());
            res += str += " ";
        }
        
        res.erase(res.size()-1);
        
        return res;
    }
};