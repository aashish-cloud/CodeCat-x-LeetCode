class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> bucket(100001, -1);

        for(int i = 0; i < heights.size(); i++)
            bucket[heights[i]] = i;
        
        vector<string> ans;

        for(int i = 100000; i >= 1; i--)
            if(bucket[i] > -1)
                ans.push_back(names[bucket[i]]);

        return ans;
    }
};