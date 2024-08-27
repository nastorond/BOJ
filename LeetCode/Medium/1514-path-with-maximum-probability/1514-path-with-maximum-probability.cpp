class Solution {
public:
    vector<vector<pair<int, double>>> gp;
    
    double sol(int n, int start_node, int goal) {
        priority_queue<pair<double, int>> pq;
        vector<double> visited(n, 0);
        
        pq.push(make_pair(1, start_node));
        while (!pq.empty()) {
            int cur = pq.top().second;
            double value = pq.top().first; pq.pop();
            
            if (cur == goal) return value;
            
            for (int i=0; i<gp[cur].size(); i++) {
                int next = gp[cur][i].first;
                double nextVal = gp[cur][i].second;
                
                if (visited[next] < value * nextVal) {
                    visited[next] = value*nextVal;
                    pq.push(make_pair(visited[next], next));
                }
            }
        }
        return 0;
    }
    
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        gp.resize(n);
        
        for (int i=0; i<edges.size(); i++) {
            gp[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            gp[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        
        return sol(n, start_node, end_node);
    }
};