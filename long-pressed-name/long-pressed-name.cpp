class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // int start = 0, end = 0;
        int j = 0;
int i = 0;
        int count[26] = {0};
    
        for(; i < name.size();) {
            char el = name[i];
            count[el - 'a']++;

            while(i < name.size() && name[++i] == el) {
                count[el - 'a']++;
            }   

            if(typed[j] == el) {
                count[el - 'a']--;

                while(j < typed.size() && typed[++j] == el) {
                    // if(typed[j] -'a' != el - 'a')
                    //     return false;
                    // else {
                        count[el - 'a']--;
                    // }
                }

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