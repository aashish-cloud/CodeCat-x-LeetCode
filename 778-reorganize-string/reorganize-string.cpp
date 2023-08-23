class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        for(char c : s) m[c]++;

        priority_queue<pair<int, char>> pq;
        for(auto it : m)    pq.push({it.second, it.first});

        int n = s.size();
        vector<char> res(n);

        int i = 0;
        while(!pq.empty()) {
            int cnt = pq.top().first;
            int c = pq.top().second;
            
            while(cnt) {
                if(i >= n)  i = 1;
                res[i] = c;
                i += 2;
                cnt--;
            }

            pq.pop();
        }

        string str = "";
        int j = 0;
        while(j < n - 1) {
            if(res[j] == res[j + 1])    return "";
            str += res[j];
            j++;
        }
        
        return str + res[j];
    }
};