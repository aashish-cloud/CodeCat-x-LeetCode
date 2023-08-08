class Solution {
public:
    void allSubsetSum(int i, int total, vector<int> &sum, vector<int> &nums) {
        if(i == nums.size()) {
            sum.push_back(total);
            return;
        }
        
        allSubsetSum(i + 1, total + nums[i], sum, nums);
        allSubsetSum(i + 1, total, sum, nums);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int N = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + N);
        vector<int> right(nums.begin() + N, nums.end());

        vector<int> sm_left;
        allSubsetSum(0, 0, sm_left, left);

        vector<int> sm_right;
        allSubsetSum(0, 0, sm_right, right);

        sort(sm_right.begin(), sm_right.end());

        int ans = INT_MAX;
        for(int i = 0; i < sm_left.size(); i++) {
            int reqSum = goal - sm_left[i];
            int it = lower_bound(sm_right.begin(), sm_right.end(), reqSum) - sm_right.begin();
            
            if(it > 0)
                ans = min(ans, abs(goal - sm_left[i] - sm_right[it - 1]));
            if(it < sm_right.size())
                ans = min(ans, abs(goal - sm_left[i] - sm_right[it]));

            // int closestValue;
            // if(it < sm_right.size() && (sm_right[it] == reqSum || it == 0))
            //     closestValue  = sm_left[i] + sm_right[it];
            // else
            //     closestValue  = sm_left[i] + sm_right[it - 1];

            // ans = min(ans, abs(goal - closestValue));
        }

        return ans;
    }
};