class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // U : Pick highest number and replace it with sqrt;
        // M : Priority queue;
        // P : Add all elements to priority queue, pop the queue and add sqrt of front number to the queue, add up rest of queue at end after k secs;
        // I :
        priority_queue<long long> q;
        long long res = 0;
        
        for(auto& n : gifts)
        {
            q.push(n);
        }
        
        for(int i = 0; i < k; i++)
        {
            q.push(sqrt(q.top())); q.pop();
        }
        
        while(!q.empty())
        {
            res += q.top(); q.pop();
        }
        
        return res;
        
        // R : Wasn't flooring the numbers
        // E : t (n log n) s (n)
    }
};