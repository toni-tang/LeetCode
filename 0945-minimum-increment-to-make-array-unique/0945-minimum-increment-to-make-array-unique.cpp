class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s;
        priority_queue<int, vector<int>, greater<int>> dups;
        
        for(auto n : nums) {
            if(s.find(n) != s.end()) {
                dups.push(n); 
            }
            else {
                s.insert(n);
            }  
        }
        
        int res = 0;
        vector<int> tmp;
        for(auto it = s.begin(); it != s.end(); it++) {
            tmp.push_back(*it);
        }
        
        for(int i = 0; i < tmp.size(); i++) {
            if(i != tmp.size()-1) {
                int diff = tmp[i+1] - tmp[i] - 1;
                if(diff >= 1) {
                    int increment = 1;
                    while(diff-- && !dups.empty() && dups.top() <= tmp[i]) {
                        res += increment + (tmp[i] - dups.top());
                        increment++;
                        dups.pop();
                    }
                }
            }
            else {
                int increment = 1;
                while(!dups.empty()) {
                    res += increment + (tmp[i] - dups.top());
                    increment++;
                    dups.pop();
                }
            }
        }
        
        return res;
    }
};