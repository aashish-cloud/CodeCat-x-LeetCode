class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> m;
        for(auto c : candyType) m[c]++;

        int canEat = candyType.size() / 2;

        if(canEat > m.size())
            return m.size();
        return canEat;
    }
};