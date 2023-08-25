class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const vector<int>& a, const vector<int>& b){
            double eucDistA = sqrt(pow(a[0],2) + pow(a[1],2));    
            double eucDistB = sqrt(pow(b[0],2) + pow(b[1],2)); 
            return eucDistA > eucDistB;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq; 
        
        for(auto i : points) {
            pq.push(i);
        }
        
        vector<vector<int>> res;
        while(k--) {
            res.push_back(pq.top()); pq.pop();
        }
        
        return res;
    }
};