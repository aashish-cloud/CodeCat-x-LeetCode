class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxi = INT_MIN, mini = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi)
                maxi = nums[i];

            if(nums[i] < mini)
                mini = nums[i];
        }
        
        vector<int> count(maxi - mini + 1, 0);

        for(int i = 0; i < nums.size(); i++) {
            count[nums[i] - mini]++;
        }

        for(int i = count.size() - 1; i >= 0; i--) {
            k -= count[i];
            if(k <= 0) {
                return i + mini;
            }
        }

        return 0;
    }
};