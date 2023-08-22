class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        
        while(columnNumber) {
            int rem = columnNumber % 26;
            if(rem) res += char(65 + rem - 1);
            else {res += 'Z'; columnNumber -= 26;}
            columnNumber /= 26;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};