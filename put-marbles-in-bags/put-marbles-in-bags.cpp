class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> v_sum;

        for(int i = 0; i < n - 1; i++)
            v_sum.push_back(weights[i] + weights[i + 1]);

        sort(v_sum.begin(), v_sum.end());

        int cnt = 0;
        long sm_min = 0, sm_max = 0;
        while(cnt < (k - 1)) {
            sm_min += v_sum[0 + cnt];
            sm_max += v_sum[v_sum.size() - 1 - cnt];
            cnt++;
        }

        return sm_max - sm_min;
    }
};