class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        
        for(auto& edge : times) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        
        queue<int> q;
        q.push(k);
    
        int res = 0;
        int cnt = n;
        while(!q.empty()) {
            int curr = q.front(); q.pop(); cnt--;
            int currDistance = distance[curr];

            for(auto& [dest, weight] : adj[curr]) {
                int newDist = weight + currDistance;
                if(newDist < distance[dest]) {
                    distance[dest] = newDist;
                    q.push(dest);
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(distance[i] != INT_MAX) {
                res = max(res, distance[i]);
            }
        }
        
        return cnt <= 0 ? res : -1;
    }
};