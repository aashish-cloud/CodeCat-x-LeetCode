class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        bool swapped = false;
        int n = names.size();

        for(int i = 0; i < n; i++) {
            swapped = false;

            for(int j = 0; j < n - 1; j++) {
                if(heights[j] < heights[j + 1]) {
                    swap(heights[j], heights[j + 1]);
                    swap(names[j], names[j + 1]);
                    swapped = true;
                }
            }

            if(!swapped)
                break;
        }

        return names;
    }
};