class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n == 1)
            return 0;
        
        vector<int> maxToRight(n, 0);
        vector<int> maxToLeft(n, 0);  

        for(int i = n - 2; i >= 0; i--) {
            maxToRight[i] = max(height[i + 1], maxToRight[i + 1]);
        }

        for(int i = 1; i < n; i++) {
            maxToLeft[i] = max(height[i - 1], maxToLeft[i - 1]);
        }

        int water = 0, maxR = 0, maxL = 0;

        for(int i = 0; i < n; i++) {
            if(maxToRight[i] < height[i])
                maxR = 0;
            else if(maxToLeft[i] < height[i])
                maxL = 0;
            else {
                maxL = maxToLeft[i];
                maxR = maxToRight[i];
            }

            water += max(min(maxL, maxR) - height[i], 0);
        }  

        return water;
    }
};