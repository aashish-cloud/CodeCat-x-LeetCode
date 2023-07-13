class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(st.size() && s[i] == st.top())    st.pop();
            else    st.push(s[i]);
        }

        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }

        for(int i = 0; i < str.size() / 2; i++)
            swap(str[i], str[str.size() - 1 - i]);
        
        return str;
    }
};