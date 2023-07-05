class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n == 1)
            return 0;
        
        vector<int> maxToRight(n, 0);
        vector<int> maxToLeft(n, 0); 

        maxToLeft[0] = height[0];
        maxToRight[n - 1] = height[n - 1]; 

        for(int i = n - 2; i >= 0; i--) {
            maxToRight[i] = max(height[i], maxToRight[i + 1]);
        }

        for(int i = 1; i < n; i++) {
            maxToLeft[i] = max(height[i], maxToLeft[i - 1]);
        }

        int water = 0;

        for(int i = 0; i < n; i++) {
            water += min(maxToLeft[i], maxToRight[i]) - height[i];
        }  

        return water;
    }
};