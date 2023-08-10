class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e14;

        while(l < r) {
            long long mid = (l + r) / 2, washed = 0;
            for(int rank : ranks)
                washed += sqrt(mid/rank);

            if(washed >= cars)  r = mid;
            else    l = mid + 1;
        }

        return l;
    }
};