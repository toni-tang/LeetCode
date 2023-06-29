class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        auto compare = [](const pair<int, int>& p1, const pair<int, int>& p2) 
        {
            return p1.second > p2.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        unordered_map<int, int> mp;
        
        for(auto n : arr) 
        {
            mp[n]++;
        }
        
        for(auto it : mp) 
        {
            pq.push(it);   
        }
        
        while (!pq.empty()) {
            pair<int, int> pair = pq.top(); 
            if(pair.second <= k)
            {
                k -= pair.second;
                pq.pop();
            }
            else
            {
                break;
            }
        }
        
        return pq.size();
    }
};