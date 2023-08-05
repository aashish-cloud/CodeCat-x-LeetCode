class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(auto i : nums)  sum += i;
        if(sum % 2 == 1)    return false;
        
        int k = sum / 2;
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));

        dp[n - 1][0] = 1;
        for(int j = 1; j <= k; j++)
            if(nums[n - 1] - j == 0)    dp[n - 1][j] = 1;
            else dp[n - 1][j] = 0;
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= k; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                bool take = 0;
                if(j - nums[i] >= 0)
                    take = dp[i + 1][j - nums[i]];
                bool notTake = dp[i + 1][j];

                dp[i][j] = take | notTake;
            }
        }

        return dp[0][k];
    }
};