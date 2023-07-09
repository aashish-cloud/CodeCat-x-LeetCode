class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 1 || nums[n - 1] < 0)
            return 1;
        
        int cursor = 0;
        while(cursor < n && nums[cursor] <= 0)    cursor++;
        
        while(cursor < n) {
            if(cursor - 1 >= 0 && nums[cursor - 1] != nums[cursor] - 1) {
                if((nums[cursor - 1] < 0 && nums[cursor] == 1) || (nums[cursor - 1] == nums[cursor])) {
                    cursor++;
                    continue;
                }
                return nums[cursor - 1] < 0 ? 1 : nums[cursor - 1] + 1;
            }
            
            cursor++;
        }
        
        return nums[cursor - 1] + 1; 
    }
};