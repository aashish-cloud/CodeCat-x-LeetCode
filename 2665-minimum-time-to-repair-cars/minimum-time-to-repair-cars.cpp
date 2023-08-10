class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e15;
        long long ans = 0;
        while(l < r) {
            long long mid = (l + r) / 2;
            
            long long washed = 0;
            for(int rank : ranks)
                washed += sqrt(mid/rank);

            cout << washed << " ";

            if(washed >= cars) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};