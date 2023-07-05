class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int , int>> v;

        for(int i = 0; i < n; i++) {
            int el = nums[i];
            int start = i;
            while((i + 1 < n) && nums[i + 1] == el)
                i++;
            
            v.push_back({el, i - start + 1});
        }

        int ans = 0;

        if(v.size() == 1 && v[0].first == 1)
            return v[0].second - 1;
        
        for(int i = 0; i < v.size(); i++) {
            if((i > 0 && i < v.size() - 1) && v[i].first == 0 && v[i].second == 1) {
                ans = max(v[i - 1].second + v[i + 1].second, ans);
            } else if(v[i].first == 1) {
                ans = max(ans, v[i].second);
            }
        }

        return ans;
    }
};