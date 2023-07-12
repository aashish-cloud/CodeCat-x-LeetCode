class Solution {
public:
    bool findSafeNodes(vector<vector<int>> &graph, vector<int> &inStack, vector<int> &vis, int node) {
        vis[node] = 1;
        inStack[node] = 1;

        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(findSafeNodes(graph, inStack, vis, it)) return true;
            } else if(inStack[it]) {
                return true;
            }
        }

        inStack[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> inStack(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i])
                findSafeNodes(graph, inStack, vis, i);
        }

        for(int i = 0; i < n; i++) {
            if(!inStack[i])
                ans.push_back(i);
        }

        return ans;
    }
};