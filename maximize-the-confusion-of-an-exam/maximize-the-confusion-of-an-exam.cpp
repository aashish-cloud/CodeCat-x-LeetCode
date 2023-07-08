class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
            int maxi = 0;
            int n = answerKey.size();
            int cnt = k;

            for(int left = 0, right = 0; right < n; right++) {
                if(answerKey[right] == 'F') cnt--;
                while(cnt < 0) {
                    if(answerKey[left] == 'F')
                        cnt++;
                    left++;
                }   
                maxi = max(maxi, right - left + 1);
            }

            cnt = k;

            for(int left = 0, right = 0; right < n; right++) {
                if(answerKey[right] == 'T') cnt--;
                while(cnt < 0) {
                    if(answerKey[left] == 'T')
                        cnt++;
                    left++;
                }
                maxi = max(maxi, right - left + 1);
            }

            return maxi;
    }
};