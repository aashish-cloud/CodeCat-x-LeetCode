class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxArr(n, 0);
        int ans = 0;

        maxArr[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxArr[i] = max(nums[i], maxArr[i + 1]);
        }

        for(int i = 0; i < n; i++) {
            ans = max(ans, maxArr[i] - nums[i]);
        }

        if(ans == 0)    return -1;
        return ans;
    }
};