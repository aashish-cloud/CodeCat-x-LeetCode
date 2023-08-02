class Solution {
public:
    void perm(map<int, int> &counter, vector<int> cmb, vector<vector<int>> & p, int n) {
        if(cmb.size() == n) {
            p.push_back(cmb);
            return;
        }

        for(auto [key, value] : counter) {
            if(value == 0)  continue;

            cmb.push_back(key); --counter[key];
            perm(counter, cmb, p, n);
            cmb.pop_back(); ++counter[key];
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        map<int, int> counter;

        for(auto it : nums) ++counter[it];
        vector<vector<int>> p;
        vector<int> cmb;

        perm(counter, cmb, p, nums.size());
        return p;
    }
};