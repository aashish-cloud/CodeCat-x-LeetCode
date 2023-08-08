class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        // if(nums[0] < nums[nums.size() - 1]) {
            
        // } else {
            while(l <= r) {
                int mid = (l + r) / 2;

                if(nums[mid] == target) return mid;

                if(nums[l] > nums[r]) {
                    if(nums[l] < nums[mid] && target >= nums[l] && target < nums[mid])    r = mid - 1;
                    else if(nums[l] > nums[mid] && (target >= nums[l] || target < nums[mid]))   r = mid - 1;
                    else    l = mid + 1;
                } else {
                    if(target > nums[mid])    l = mid + 1;
                    else    r = mid - 1;    
                }
            }
        // }

        return -1;
    }
};