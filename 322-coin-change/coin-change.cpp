class Solution {
public:
    int helper(int i, int k, vector<int> &coins, int cnt, vector<vector<int>> &dp) {
        if(k == 0)  return dp[i][k] = cnt;
        if(i == coins.size())   return dp[i][k] = INT_MAX;

        if(dp[i][k] != -1) {
            return (long)dp[i][k] + cnt > INT_MAX ? INT_MAX : dp[i][k] + cnt;
        }  

        int take = INT_MAX;
        if(k - coins[i] >= 0)
            take = helper(i, k - coins[i], coins, cnt + 1, dp);
        int notTake = helper(i + 1, k, coins, cnt, dp);

        dp[i][k] = abs(min(take, notTake) == INT_MAX ? INT_MAX : min(take, notTake) - cnt);
        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
        helper(0, amount, coins, 0, dp);

        return dp[0][amount]  == INT_MAX? -1 : dp[0][amount];
    }
};