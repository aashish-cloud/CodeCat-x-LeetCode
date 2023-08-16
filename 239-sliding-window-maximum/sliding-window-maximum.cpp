class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /* 10 1 3 2 */
        vector<int> ans;
        deque<int> dq;
        
        for(int i = 0; i < k; i++) {
            while(dq.size() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for(int i = k; i < nums.size(); i++) {
            while(dq.size() && dq.front() < (i - k + 1))   dq.pop_front();
            while(dq.size() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};