class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0; i < n; i++) {
            int pair = nums[i] << 10;
            nums[i] = pair | nums[n + i];
        }

        for(int i = n - 1; i >= 0; i--) {
            nums[2 * i + 1] = nums[i] & 1023;
            nums[2 * i] = nums[i] >> 10;
        }

        return nums;
    }
};