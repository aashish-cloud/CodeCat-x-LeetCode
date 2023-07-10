class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();

        map<char, int> m_arr;
        map<char, int> m_tar;

        for(int i = 0; i < n; i++) {
            m_arr[arr[i]]++;
            m_tar[target[i]]++;
        }

        return m_arr == m_tar ? true : false;    
    }
};