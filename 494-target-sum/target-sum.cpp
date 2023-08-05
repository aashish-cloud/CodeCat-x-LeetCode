class Solution {
public:
    int helper(int idx, int ex, int k, vector<int> &nums) {
        if(idx == nums.size()) {
            if(ex == k)
                return 1;
            return 0;
        }
        
        int a = helper(idx + 1, ex + nums[idx], k, nums);
        int s = helper(idx + 1, ex - nums[idx], k, nums);
    
        return a + s;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, 0, target, nums);
    }
};