class Solution {
public:
    string reverseWords(string s) {
        string word = "", result = "";
        
        vector<string> words;
        
        for(int i = 0; i < s.length(); i++) {
            
            if(s[i] != ' ')
                word += s[i];

            if(s[i] == ' ' || i == s.length() - 1) {
                if(word != "") {
                    words.push_back(word);
                    word = "";
                }
            }
            
        }
        
        for(int i = words.size() - 1; i >= 0 ; i--) {
            if(i != 0) {
                result += words[i] + " ";            
            } else {
                result += words[i];
            }
        }
        
        return result;
    }
};