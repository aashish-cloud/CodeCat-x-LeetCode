class Solution {
public:
    int helper(int idx, int k, vector<int> &nums, vector<vector<int>> &dp) {
        if(k == 0) return 1;
        if(idx == nums.size())  return 0;

        if(dp[idx][k] != -1)    return dp[idx][k];

        if(k - nums[idx] >= 0)
            if(helper(idx + 1, k - nums[idx], nums, dp))   return dp[idx][k] = 1;
        if(helper(idx + 1, k, nums, dp))    return dp[idx][k] = 1;

        return dp[idx][k] = 0;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(auto n : nums)  sum += n;
        if(sum % 2 == 1)    return false;
        
        int k = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int> (k + 1, -1));
        return helper(0, k, nums, dp);
    }
};