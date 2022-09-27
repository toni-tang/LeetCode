class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(begin(stones), end(stones));
        int y = 0, x = 0;
    
        while(pq.size() > 1)
        {
            y = pq.top(); pq.pop();
            x = pq.top(); pq.pop();

            if(y > x) pq.push(y-x);    
        }
        
        return pq.size() == 1 ? pq.top() : 0;
    }
};