class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string pre = "";

        for(int i = 0; i < s.size() / 2; i++) {
            pre += s[i];

            int j = i + 1;    
            while(j < s.size() && s.substr(j, i + 1) == pre) {
                j += i + 1;
            }

            if(j == s.size())   return true;
        }

        return false;
    }
};