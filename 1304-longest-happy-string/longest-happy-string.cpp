class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a)   pq.push({a, 'a'});
        if(b)   pq.push({b, 'b'});
        if(c)   pq.push({c, 'c'});

        string str = "";
        pair<int, char> tp;
        bool popped = false;

        while(!pq.empty()) {
            if( str.size() > 1 && pq.top().second == str[str.size() - 1] 
                && pq.top().second == str[str.size() - 2] ) {
                    tp = pq.top();
                    pq.pop();
                    if(pq.empty())  break;
                    popped = true;
                } 

            int cnt = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            str += c;
            cnt--;

            if(cnt > 0) pq.push({cnt, c});

            if(popped) {
                pq.push(tp);
                popped = false;
            }  
        }   

        return str;        
    }
};