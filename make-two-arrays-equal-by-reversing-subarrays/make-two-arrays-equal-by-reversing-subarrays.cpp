class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();

        for(int i = 0; i < n; i++) {
            int key = target[i];
            bool found = false;
            
            for(int j = i; j < n; j++) {
                if(arr[j] == key) {
                    reverse(arr.begin() + i, arr.begin() + j + 1);
                    found = true;
                }
            }

            if(!found)
                return false;
        }

        return true;    
    }
};