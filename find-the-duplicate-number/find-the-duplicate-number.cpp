class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int j = abs(nums[i]) - 1;

            if(nums[j] < 0)
                return abs(nums[i]);
            else
                nums[j] = -1*nums[j];
        }

        return 0;
    }
};