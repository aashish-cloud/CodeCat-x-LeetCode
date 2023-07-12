class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int count[26] = {0};
    
        while(i < name.size()) {
            char el = name[i];
            count[el - 'a']++;

            while(i < name.size() && name[++i] == el)   count[el - 'a']++;

            if(typed[j] == el) {
                count[el - 'a']--;

                while(j < typed.size() && typed[++j] == el) count[el - 'a']--;

                if(count[el - 'a'] > 0) return false;
                else count[el - 'a'] = 0;
            } else {
                return false;
            }
        }

        if(j < typed.size() && i == name.size())
            return false;

        return true;
    }
};