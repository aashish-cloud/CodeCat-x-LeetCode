class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, int> bucket;

        for(int i = 0; i < heights.size(); i++)
            bucket[heights[i]] = i;
        
        vector<string> ans;

        for(auto itr = bucket.rbegin(); itr != bucket.rend(); itr++)
            ans.push_back(names[itr->second]);

        return ans;
    }
};