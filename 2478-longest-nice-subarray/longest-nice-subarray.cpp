class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr = 0, i = 0, ans = 1;
        for(int j = 0; j < nums.size(); j++) {
            while(i < j && (curr & nums[j]) != 0)  curr &= ~nums[i++];
            curr |= nums[j];
            ans = max(ans, j - i + 1);
        }

        return ans;    
    }
};