class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long score = 0;
        while(k) {
            int el = pq.top();
            score += el;
            
            pq.pop();
            pq.push(ceil(el / 3.0));

            k--;
        }

        return score;
    }
};