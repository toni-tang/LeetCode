class Graph {
public:
    vector<vector<pair<int, int>>> adjacencyList;
    
    Graph(int n, vector<vector<int>>& edges) {
        adjacencyList.resize(n);
        for(auto& edge: edges) {
            adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
                      
    int dijkstra(int start, int end) {
        int n = adjacencyList.size();
        vector<int> distance(n, INT_MAX);
        distance[start] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({start, 0});
        
        while(!pq.empty()) {
            int currNode = pq.top().first;
            int currDist = pq.top().second;
            pq.pop();
            
            if(currDist > distance[currNode]) {
                continue;
            }
            
            for(auto& edge : adjacencyList[currNode]) {
                int neighbor = edge.first;
                int dist = edge.second;
                
                int newDist = dist + distance[currNode];
                if(distance[neighbor] > newDist) {
                    distance[neighbor] = newDist;
                    pq.push({neighbor, newDist});
                }
            }
        }
        
        return (distance[end] == INT_MAX) ? -1 : distance[end];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */