class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        
        for(int n : nums)
            m[n]++;
        
        for(auto it : m)
            if(it.second > 1)
                return true;

        return false; 
    }
};