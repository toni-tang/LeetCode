class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degrees(n, 0);
        vector<int> res(n, 0);
        
        for(auto p : pre) {
            adj[p[0]].push_back(p[1]);
            degrees[p[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degrees[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int curr = q.front(); q.pop(); res[n-1] = curr; n--;
            for(auto node : adj[curr]) {
                if (--degrees[node] == 0) q.push(node);
            }
        }
        
        return n == 0 ? res : vector<int>();
    }
};