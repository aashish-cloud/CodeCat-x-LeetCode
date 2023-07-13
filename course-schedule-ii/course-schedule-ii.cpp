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

        vector<int> ans;
        while(!q.empty()) {
            int course = q.front();
            ans.push_back(course);

            for(auto nextCourse : graph[course]) {
                inDegree[nextCourse]--;

                if(inDegree[nextCourse] == 0)
                    q.push(nextCourse);
            }

            q.pop();
        }

        for(auto i : inDegree)
            if(i)    return {};

        return ans;
    }
};