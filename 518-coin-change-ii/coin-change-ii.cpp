class Solution {
public:
    int helper(int i, int k, vector<int> &coins, vector<vector<int>> &dp) {
        if(k == 0)  return 1;
        if(i == coins.size())   return 0;

        if(dp[i][k] != -1)  return dp[i][k];

        int take = 0;
        if(k - coins[i] >= 0)
            take = helper(i, k - coins[i], coins, dp);
        int notTake = helper(i + 1, k, coins, dp);

        return dp[i][k] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return helper(0, amount, coins, dp);
    }
};