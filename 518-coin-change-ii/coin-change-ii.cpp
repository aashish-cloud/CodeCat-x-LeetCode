class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, 0));
        int n = coins.size();

        dp[n - 1][0] = 1;
        for(int j = 1; j <= amount; j++)
            if(j - coins[n - 1] == 0)   dp[n - 1][j] = 1;
            else dp[n - 1][j] = j - coins[n - 1] >= 0 ? dp[n - 1][j - coins[n - 1]] : 0;

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < amount + 1; j++) {
                int take = 0;
                if(j - coins[i] >= 0)
                    take = dp[i][j - coins[i]];
                int notTake = dp[i + 1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[0][amount];
    }
};