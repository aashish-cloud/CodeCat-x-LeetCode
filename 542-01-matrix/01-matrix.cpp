class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int> (n, 0));
        vector<vector<int>> vis(m, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1)  continue;
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }

        int delRow[] = {-1, 1, 0,  0};
        int delCol[] = { 0, 0, 1, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            dist[row][col] = steps;

            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if(!vis[nrow][ncol]) { 
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, steps + 1});
                    }
                }   
            }

            q.pop();
        }

        return dist;  
    }
};