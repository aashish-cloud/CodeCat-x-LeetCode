class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, cnt = 0, prod = 1;
        int n = nums.size();
        
        while(end < n) {
            prod *= nums[end];

            while(start < end && prod >= k) {
                prod /= nums[start];
                start++;
            }

            if(prod < k) {
                cnt = cnt + (end - start + 1);
            }

            end++;
        }

        return cnt;
    }
};