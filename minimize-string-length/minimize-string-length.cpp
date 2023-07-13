class Solution {
public:
    int minimizedStringLength(string s) {
        int count[26] = {0};
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        for(int cnt : count)
            if(cnt)
                ans++;
        
        return ans;
    }
};