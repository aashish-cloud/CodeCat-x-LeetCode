class Solution {
public:
    bool isValid(vector<int> candies, long long k, int candy) {
        if(candy == 0)  return true;

        long long allocated = 0;
        for(int i = 0; i < candies.size(); i++) {
            allocated += candies[i] / candy;
        }

        return allocated >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = *max_element(candies.begin(), candies.end());

        int ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(isValid(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};