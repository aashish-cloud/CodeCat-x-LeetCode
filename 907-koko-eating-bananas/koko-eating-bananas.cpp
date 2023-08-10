class Solution {
public:
    bool isValid(vector<int> piles, int hours, int speed) {
        long hoursTaken = 0;
        for(int i = 0; i < piles.size(); i++) {
            hoursTaken += piles[i] / speed;
            if(piles[i] % speed)    hoursTaken++;
        }
        
        return hoursTaken <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(isValid(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            } 
        }
    
        return ans;
    }
};