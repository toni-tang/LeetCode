// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<bool> todo(numCourses, false), done(numCourses, false);
//         vector<vector<int>> adj(numCourses, vector<int>());
        
//         for(int i = 0; i < prerequisites.size(); i++) {
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
        
//         for (int i = 0; i < numCourses; i++) {
//             if (!done[i] && !acyclic(adj, todo, done, i)) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
// private:
//     bool acyclic(vector<vector<int>> adj, vector<bool>& todo, vector<bool>& done, int node) {
//         if (todo[node]) return false;
//         if (done[node]) return true;
        
//         todo[node] = done[node] = true;

//         for (int n : adj[node]) {
//             if (!acyclic(adj, todo, done, n)) {
//                 return false;
//             }
//         }
        
//         todo[node] = false;
        
//         return true;
//     }
// };

class Solution  {
public: 
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);

        for (auto &p: pre) {
            adj[p[0]].push_back(p[1]);
            degree[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front(); q.pop(); n--;
            for (auto next: adj[curr]) {
                if (--degree[next] == 0) q.push(next);   
            }
        }

        return n == 0;
    }    
};
