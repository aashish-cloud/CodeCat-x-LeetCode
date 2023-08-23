class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if(nums.size() == 1)    return nums;
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i - 1] == nums[i] || nums[i] == nums[i + 1] || nums[i - 1] + 1 == nums[i] || nums[i] + 1 == nums[i + 1]);
            else ans.push_back(nums[i]);
        }

        if(nums[0] != nums[1] && nums[0] + 1 != nums[1]) ans.push_back(nums[0]);
        if(nums[nums.size() - 1] != nums[nums.size() - 2] && nums[nums.size() - 1] != nums[nums.size() - 2] + 1) ans.push_back(nums[nums.size() - 1]);

        return ans;
    }
};