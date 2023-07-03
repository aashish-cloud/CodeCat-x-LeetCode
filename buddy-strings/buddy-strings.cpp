class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        
        int cnt = 0;
        map<char, int> sm, sg;
        for(int i = 0; i < s.size(); i++) {
            sm[s[i]]++;
            sg[goal[i]]++;

            if(s[i] != goal[i])
                cnt++;
            
            if(cnt > 2)
                return false;
        }

        for(auto itr : sm) {
            if(sm[itr.first] != sg[itr.first])
                return false;
        }

        if(cnt == 0) {
            for(auto itr : sm) {
                if(itr.second > 1)
                    return true;
            }
        }

        return cnt == 2;
    }
};