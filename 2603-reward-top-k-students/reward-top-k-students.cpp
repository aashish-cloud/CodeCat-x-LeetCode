class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        vector<int> ans;
        map<string, int> positive, negative;

        for(string s : positive_feedback)   positive[s]++;
        for(string s : negative_feedback)   negative[s]++;

        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < report.size(); i++) {
            
            int n = report[i].size(), score = 0;

            for(int j = 0; j < n; j++) {
                string word = "";
                
                while(j < n && report[i][j] != ' ')  word += report[i][j++];
                
                score += positive[word] ? 3 : 0;
                score += negative[word] ? -1 : 0; 
            }
            
            pq.push({score, -student_id[i]});
        }

        while(k) {
            ans.push_back(-pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};