class Solution {
public:
    int countSegments(string s) {
        int i = 0, j = 0;
        int cnt = 0;
        int n = s.length();

        while(j < n) {
            if(s[j] == ' ') i++, j++;
            else  j++;

            if((s[j] == ' ' || j == n) && s[i] != ' ' && s[i] != '\0') {
                cout << j << " " << i;
                i = j;
                cnt++;
            } 

        }    

        return cnt;
    }
};