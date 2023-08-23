class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int current_group = 0, i = 0, ans = 1;
        for(int j = 0; j < nums.size(); j++) {
            while(i < j && (current_group & nums[j]) != 0)  current_group &= ~nums[i++];
            current_group |= nums[j];
            ans = max(ans, j - i + 1);
        }

        return ans;    
    }
};