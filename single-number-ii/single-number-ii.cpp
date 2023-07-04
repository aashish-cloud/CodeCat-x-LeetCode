class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit_cnt(32);
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int j = 31;
            
            while(n && j >= 0) {
                if(n & 1) bit_cnt[j] += 1;
                n = n >> 1;
                j--;
            }
        }

        long long base = 1;
        int dec = 0;
        for(int i = 31; i >= 0; i--) {
            if(bit_cnt[i])
                dec += (bit_cnt[i] % 3) * base;
            base *= 2;
        }

        return dec;
    }
};