class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        int n = s.size();

        while(j < n && s[j] != '*') j++;

        int i = j - 1;

        while(j < n) {
            if(s[j] == '*') i--;
            else swap(s[++i], s[j]);

            j++;
        }

        if(i < 0)
            return "";

        string ans;
        for(int k = 0; k <= i; k++) {
            ans += s[k];
        }

        return ans;
    }
};