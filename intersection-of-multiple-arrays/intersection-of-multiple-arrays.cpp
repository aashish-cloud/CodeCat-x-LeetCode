class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int bucket[1001] = {0};

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                if(bucket[nums[i][j]] < i + 1)
                    bucket[nums[i][j]]++;
            }
        }

        vector<int> ans;

        for(int i = 0; i < 1001; i++) {
            if(bucket[i] == nums.size())
                ans.push_back(i);
        }

        return ans;
    }
};