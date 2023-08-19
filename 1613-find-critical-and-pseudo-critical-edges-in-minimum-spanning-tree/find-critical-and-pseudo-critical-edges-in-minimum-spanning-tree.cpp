class DSU {
    vector<int> parent;
    vector<int> rank;

    public: 

    DSU(int n) {
        parent.resize(n, 0);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++)  parent[i] = i;
    }

    int Find(int x) {
        return parent[x] == x ? x : parent[x] = Find(parent[x]); 
    }

    void Union(int x, int y) {
        int xset = Find(x), yset = Find(y);

        if(xset != yset) {
            if(rank[xset] < rank[yset]) {
                parent[xset] = yset;
                rank[yset] += rank[xset]; 
            } else {
                parent[yset] = xset;
                rank[xset] += rank[yset];
            }
        }
    }
};

class Solution {
public:
    int mst(int n, vector<vector<int>>& edges, int includeEdge, int excludeEdge) {
        DSU dsu(n);
        int weight = 0;

        if(includeEdge != -1) {
            weight += edges[includeEdge][2];
            dsu.Union(edges[includeEdge][0], edges[includeEdge][1]);
        }

        for(int i = 0; i < edges.size(); i++) {
            const auto edge = edges[i];
            if(i == excludeEdge)    continue;
            if(dsu.Find(edge[0]) == dsu.Find(edge[1]))  continue;
            dsu.Union(edge[0], edge[1]);
            weight += edge[2];
        }

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++)   edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // for(int i = 0; i < edges.size(); i++) {
        //     cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << " " << endl;
        // }

        int realMST = mst(n, edges, -1, -1);
        // cout << realMST;
        vector<int> criticalEdges, pseudoCriticalEdges;

        for(int i = 0; i < edges.size(); i++) {
            if(mst(n, edges, -1, i) != realMST) {
                criticalEdges.push_back(edges[i][3]);
            }    
            
            else if(mst(n, edges, i, -1) == realMST)    pseudoCriticalEdges.push_back(edges[i][3]);
        }

        return {criticalEdges, pseudoCriticalEdges};
    }
};