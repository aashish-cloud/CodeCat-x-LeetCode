class Solution {
public:
    bool detectCycle(vector<vector<int>> &graph, vector<int> &vis, vector<int> &inStack, int node) {
        vis[node] = 1;
        inStack[node] = 1;

        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(detectCycle(graph, vis, inStack, it))    return true;
            } else if(inStack[it]) {
                return true;
            }
        }

        inStack[node] = 0;
        return false;
    } 


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses, 0), inStack(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(detectCycle(graph, vis, inStack, i)) {
                    return false;
                }   
            }
        }

        return true;
    }
};