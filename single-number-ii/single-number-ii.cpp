class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans = 0;

        for(int i = 0; i < 32; i++) {
            int currBits = 0;

            for(int j = 0; j < nums.size(); j++) {
                currBits += (nums[j] & 1);
                nums[j] >>= 1;
            }

            ans |= (currBits % 3) << i;
        }

        return ans;
    }
};