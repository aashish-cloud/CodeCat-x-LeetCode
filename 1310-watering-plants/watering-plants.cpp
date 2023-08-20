class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cnt = 0;
        int bucket = capacity;
        
        for(int i = -1; i < n - 1; i++) {
            if(bucket - plants[i + 1] < 0) {
                bucket = capacity;
                cnt += 2 * (i + 1);
                i--;
            }    
            else {
                bucket -= plants[i + 1];
                cnt++;
            } 
        }

        return cnt;
    }
};