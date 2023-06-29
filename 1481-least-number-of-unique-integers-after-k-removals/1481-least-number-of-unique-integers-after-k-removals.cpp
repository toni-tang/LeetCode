class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        
        for(auto n : arr) 
        {
            mp[n]++;
        }
        
        for(auto it : mp) 
        {
            pq.push(it.second);   
        }
        
        while (!pq.empty() && k > 0) {
            k -= pq.top();
            if(k >= 0)
            {
                pq.pop();
            }
        }
        
        return pq.size();
    }
};