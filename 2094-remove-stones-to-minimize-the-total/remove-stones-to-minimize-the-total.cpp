class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        while(k) {
            int pile = pq.top();
            
            pq.pop();
            pq.push(pile - floor(pile / 2));
            
            k--;
        }

        int total = 0;
        while(!pq.empty()) {  
            total += pq.top();
            pq.pop();
        }
        
        return total;
    }
};