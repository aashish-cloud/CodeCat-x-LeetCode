class Solution {
public:
    int allJump(int i, vector<int>& nums, vector<int>& dp) {
        if(i == nums.size() - 1)    return dp[i] = 1;
        if(i > nums.size() - 1)     return 0;

        if(dp[i] != -1)     return dp[i];

        for(int j = 1; j <= nums[i]; j++) {
            if(allJump(i + j, nums, dp))    return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return allJump(0, nums, dp);
    }
};