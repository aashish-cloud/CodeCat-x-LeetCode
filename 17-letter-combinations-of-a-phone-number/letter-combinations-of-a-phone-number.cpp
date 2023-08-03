class Solution {
public:
    void helper(string digits, string cmb, int idx, vector<vector<char>> &m, vector<string> &res) {
        if(idx == digits.length()) {
            if(cmb != "") res.push_back(cmb);
            return;
        }

        for(int i = 0; i < m[digits[idx] - '0'].size(); i++) {
            helper(digits, cmb + m[digits[idx] - '0'][i], idx + 1, m, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<vector<char>> m = {{}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r', 's'}, {'t','u','v'}, {'w', 'x', 'y', 'z'}};

        helper(digits, "", 0, m, res);
        return res;
    }
};