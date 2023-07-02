class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        
        for(int n : nums)
            m[n]++;
        
        return nums.size() > m.size(); 
    }
};