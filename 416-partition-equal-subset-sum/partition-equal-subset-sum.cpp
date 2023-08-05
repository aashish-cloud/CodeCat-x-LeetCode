class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(auto i : nums)  sum += i;
        if(sum % 2 == 1)    return false;
        
        int k = sum / 2;
        vector<int> prev(k + 1, -1);

        prev[0] = 1;
        for(int j = 1; j <= k; j++)
            if(nums[n - 1] - j == 0)    prev[j] = 1;
            else prev[j] = 0;
        
        for(int i = n - 2; i >= 0; i--) {
            vector<int> curr(k + 1, -1);

            for(int j = 0; j <= k; j++) {
                if(j == 0) {
                    curr[j] = 1;
                    continue;
                }

                bool take = 0;
                if(j - nums[i] >= 0)
                    take = prev[j - nums[i]];
                bool notTake = prev[j];

                curr[j] = take | notTake;
            }

            prev = curr;
        }

        return prev[k];
    }
};