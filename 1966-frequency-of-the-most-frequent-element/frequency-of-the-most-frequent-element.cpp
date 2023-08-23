class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long maxi = 0, sum = 0, i = 0;
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while((j - i + 1) * nums[j] - sum > k)  sum -= nums[i++];
            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};