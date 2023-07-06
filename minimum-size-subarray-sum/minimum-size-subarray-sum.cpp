class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX, sum = 0;
        int i = 0, j = 0;
        for(; j < nums.size(); j++) {
            sum += nums[j];

            while(sum >= target) {
                mini = min(j - i + 1 , mini);
                sum -= nums[i];
                i++;
            }
        }

        return  i == 0 ? 0 : mini;
    }
};