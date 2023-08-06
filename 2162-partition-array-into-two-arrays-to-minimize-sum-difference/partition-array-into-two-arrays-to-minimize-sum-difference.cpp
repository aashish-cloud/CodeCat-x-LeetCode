class Solution {
public:
    void allPossibleSubsetSum(int i, int sum, int cnt, vector<int> &nums, vector<vector<int>> &m) {
        if(i == nums.size()) {
            m[cnt].push_back(sum);
            return;
        } 

        allPossibleSubsetSum(i + 1, sum + nums[i], cnt + 1, nums, m);
        allPossibleSubsetSum(i + 1, sum, cnt, nums, m);
    }

    int minimumDifference(vector<int>& nums) {
        int N = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + N);
        vector<int> right(nums.begin() + N, nums.end());

        vector<vector<int>> m_left(N + 1);
        allPossibleSubsetSum(0, 0, 0, left, m_left);
        
        vector<vector<int>> m_right(N + 1);
        allPossibleSubsetSum(0, 0, 0, right, m_right);

        int sum = 0;
        for(int s : nums)   sum += s;

        int ans = INT_MAX;

        int target = sum / 2;
        for(int i = 0; i < m_left.size(); i++) {
            sort(m_right[N - i].begin(), m_right[N - i].end());
        
            for(int j = 0; j < m_left[i].size(); j++) {
                auto it = lower_bound(m_right[N - i].begin(), m_right[N - i].end(), target - m_left[i][j]);
                if(it != m_right[N - i].end())
                    ans = min(ans, abs(sum - 2 * (m_left[i][j] + *it)));
            }
        }
        
        return ans;
    }
};