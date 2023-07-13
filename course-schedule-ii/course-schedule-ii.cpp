class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);
       vector<int> inDegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int course = 0; course < numCourses; course++) {
            if(!inDegree[course]) {
                q.push(course);
            }
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            vis[node] = 1;
            ans.push_back(node);

            for(auto it : graph[node]) {
                inDegree[it]--;

                if(inDegree[it] <= 0)
                    q.push(it);
            }

            q.pop();
        }

        for(auto isVisited : vis)
            if(!isVisited)    return {};

        return ans;
    }
};