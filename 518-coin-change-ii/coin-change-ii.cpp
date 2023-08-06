class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount + 1, 0);
        int n = coins.size();

        prev[0] = 1;
        for(int j = 1; j <= amount; j++)
            if(j - coins[n - 1] == 0)   prev[j] = 1;
            else prev[j] = j - coins[n - 1] >= 0 ? prev[j - coins[n - 1]] : 0;

        for(int i = n - 2; i >= 0; i--) {
            vector<int> curr(amount + 1, 0);
            for(int j = 0; j < amount + 1; j++) {
                int take = 0;
                if(j - coins[i] >= 0)
                    take = curr[j - coins[i]];
                int notTake = prev[j];

                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};