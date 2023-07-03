class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2, vector<int>());

        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());

        for(int n : st1) {
            if(!st2.count(n))
                answer[0].push_back(n);
        }

        for(int n : st2) {
            if(!st1.count(n))
                answer[1].push_back(n);
        }

        return answer;
    }
};