class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int prev = INT_MIN;
            if(i > 0)    prev = nums[i - 1];

            int next = INT_MAX;
            if(i != nums.size() - 1)    next = nums[i + 1];
            
            if(prev == nums[i] || nums[i] == next || prev + 1 == nums[i] || nums[i] + 1 == next);
            else ans.push_back(nums[i]);
        }

        return ans;
    }
};