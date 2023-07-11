class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxi = sum;
        
        for(int i = 1; i <= nums.size() - k; i++) {
            sum = sum - nums[i - 1] + nums[i + k - 1];
            maxi = max(maxi, sum);
        }

        return maxi / k;
    }
};