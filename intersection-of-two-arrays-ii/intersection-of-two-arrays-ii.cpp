class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int bucket[1001] = {0};
        
        for(int i = 0; i < nums1.size(); i++) {
            bucket[nums1[i]]++;
        }
        
        vector<int> ans;

        for(int i = 0; i < nums2.size(); i++) {
            if(bucket[nums2[i]]-- > 0)
                ans.push_back(nums2[i]);
        }

        return ans;
    }
};