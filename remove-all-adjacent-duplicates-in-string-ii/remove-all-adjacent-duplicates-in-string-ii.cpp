class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
    
        for(int i = 0; i < s.size(); i++) {
            if(st.size() && s[i] == st.top().first)     st.top().second++;
            else    st.push({s[i], 1});

            if(st.size() && st.top().second == k)    st.pop();
        }

        string ans = "";
        while(!st.empty()) {
            while(st.top().second--)
                ans += st.top().first;
            st.pop();
        }

        for(int i = 0; i < ans.size() / 2; i++)
            swap(ans[i], ans[ans.size() - 1 - i]);

        return ans;
    }
};