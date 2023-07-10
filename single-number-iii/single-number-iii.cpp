class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int firstXorSec = 0, mask = 1;
        for(int num : nums) firstXorSec ^= num;

        while(!(firstXorSec & mask))    mask <<= 1;

        int x = 0;
        for(int num : nums) if(num & mask)  x ^= num;

        return {x, firstXorSec^x};
    }
};