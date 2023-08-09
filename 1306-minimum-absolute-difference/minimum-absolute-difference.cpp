class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<int, vector<vector<int>>> m;
        sort(arr.begin(), arr.end());

        for(int i = 1; i < arr.size(); i++) {
            m[arr[i] - arr[i - 1]].push_back({arr[i - 1], arr[i]});
        }

        return m.begin()->second;
    }
};