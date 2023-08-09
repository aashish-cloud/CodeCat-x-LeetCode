class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int minCost = 0;
        int mini;
        int i = cost.size() - 1; 
        
        while(i >= 0) {
            int cnt = 2;

            while(i >= 0 && cnt--) {
                minCost += cost[i];
                mini = cost[i];
                i--;      
            }

            i--;     
        }

        return minCost;
    }
};