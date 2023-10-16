class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> res;
        vector<int> vec;
        int prev = 0;
        for(auto word : words) {
            if(word != "prev") {
                prev = 0;
                vec.push_back(stoi(word));
            }
            else {
               if(prev < vec.size()) {
                    prev++; 
                    res.push_back(vec[vec.size()-prev]);
               } else {
                   res.push_back(-1);
               }
            }
        }
        
        return res;
    }
};