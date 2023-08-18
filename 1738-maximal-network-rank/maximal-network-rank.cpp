class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int, int> deg;
        vector<vector<int>> adj(n);

        for(vector<int> road : roads) {
            deg[road[0]]++;
            deg[road[1]]++;
            
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = deg[i] + deg[j];
                
                bool ij = find(adj[i].begin(), adj[i].end(), j) != adj[i].end();
                bool ji = find(adj[j].begin(), adj[j].end(), i) != adj[j].end();
                
                if( ij || ji )    rank--;
                maxi = max(maxi, rank);
            }
        }

        return maxi;
    }
};