class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refill = 0, bucketA = capacityA, bucketB = capacityB;
        int i = 0, j = plants.size() - 1;

        while(i < j) {
            if(bucketA - plants[i] < 0) refill++, bucketA = capacityA;
            if(bucketB - plants[j] < 0) refill++, bucketB = capacityB;

            bucketA -= plants[i];
            bucketB -= plants[j];
        
            i++, j--; 
        }

        if(i == j)
            if(max(bucketA, bucketB) < plants[i]) refill++;

        return refill;
    }
};