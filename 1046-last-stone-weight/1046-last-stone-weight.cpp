class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int y = 0, x = 0, res = 0;
        
        if(stones.size() == 1) return stones[0];
        
        for(int& stone : stones)
        {
            pq.push(stone);
        }
        
        while(!pq.empty() && pq.size() > 1)
        {
            int n = pq.size();
            for(int i = 0; i < n/2; i++)
            {
                y = pq.top();
                pq.pop();
                x = pq.top();
                pq.pop();
                
                if(y > x)
                {
                    res = y-x;
                    pq.push(y-x);
                }   
            }
            if(pq.size() == 1) return pq.top();
            if(pq.size() == 0) return 0;
        }
        
        return res;
    }
};