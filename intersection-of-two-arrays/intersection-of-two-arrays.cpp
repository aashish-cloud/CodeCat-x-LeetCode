class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());

        for(int n : st2) {
            if(st1.count(n))
                ans.push_back(n);
        }

        return ans;
    }
};