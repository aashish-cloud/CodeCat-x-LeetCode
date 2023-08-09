class Solution {
public:
    bool isValid(int mid,vector<int>& nums,int p) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] <= mid) {
                p--;
                i++;
            }
        }

        return p <= 0;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int l=0,h=*max_element(nums.begin(),nums.end());
        int ans = 0;

        sort(nums.begin(), nums.end());

        while(l<=h){
            int mid = l+(h-l)/2;
            if(isValid(mid,nums,p)){
                ans = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }

        return ans;
    }
};