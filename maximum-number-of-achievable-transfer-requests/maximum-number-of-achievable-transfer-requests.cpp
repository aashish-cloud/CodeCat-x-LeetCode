class Solution {
public:
    void chooseRequests(vector<int> &buildings, int &maxi, int n, vector<vector<int>> &requests, int index, int cnt) {
        if(index == n) {
            for(int change : buildings)
                if(change)
                    return;
            
            maxi = max(maxi, cnt);
            return;
        }


        buildings[requests[index][0]]--;
        buildings[requests[index][1]]++;
        
        chooseRequests(buildings, maxi, n, requests, index + 1, cnt + 1);

        buildings[requests[index][0]]++;
        buildings[requests[index][1]]--;

        chooseRequests(buildings, maxi, n, requests, index + 1, cnt);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildings(n, 0);
        int maxi = 0;

        chooseRequests(buildings, maxi, requests.size(), requests, 0, 0);
        return maxi;
    }
};