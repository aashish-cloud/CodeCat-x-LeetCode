class Solution {
public:
    int minimizedStringLength(string s) {
        int count[26] = {0};
        int ans = 0;

        for(char c : s)  count[c - 'a']++;
        for(int cnt : count)    if(cnt) ans++;
        
        return ans;
    }
};