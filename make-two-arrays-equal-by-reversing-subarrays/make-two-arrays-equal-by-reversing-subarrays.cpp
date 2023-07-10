class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();

        int bucket[1001] = {0}; 

        for(int i = 0; i < n; i++) {
            bucket[arr[i]]++;
            bucket[target[i]]--;
        }

        for(int cnt : bucket)
            if(cnt > 0)
                return false;

        return true;
    }
};