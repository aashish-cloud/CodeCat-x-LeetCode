class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());

        int type = 0;
        int n = candyType.size();
        
        for(int i = 0; i < n; i++) {
            while(i + 1 < n && candyType[i] == candyType[i + 1]) i++;
            type++;
        }

        int canEat = n / 2;

        if(canEat > type)
            return type;
        return canEat;
    }
};