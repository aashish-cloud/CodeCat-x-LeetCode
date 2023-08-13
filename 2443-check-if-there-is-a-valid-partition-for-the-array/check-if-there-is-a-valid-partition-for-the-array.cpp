class Solution {
public:
    int isValid(int i, vector<int>& nums, vector<int>& dp) {
        if(i == nums.size())    return dp[i] = 1;
        if(i > nums.size())    return dp[i] = 0;

        if(dp[i] != -1)     return dp[i];

        if(isValid(i + 2, nums, dp)) {
            if(nums[i] == nums[i + 1])  return dp[i] = 1;
        }
        
        if(isValid(i + 3, nums, dp)) {
            bool isConsecutive = nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2];
            bool isSame = nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2];
            if(isConsecutive || isSame) return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size() + 3, -1);
        return isValid(0, nums, dp);
    }
};