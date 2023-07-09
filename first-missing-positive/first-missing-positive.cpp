class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<int> count(n + 1, 0); 

        for(int el : nums) {
            if(el >= 1 && el <= n)
            count[el] = 1;
        }

        int i = 1;
        while(i < n + 1) {
            if(count[i] == 0)
                return i;
            i++;
        }

        return i;
    }
};