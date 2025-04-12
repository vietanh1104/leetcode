// 1422. Maximum Score After Splitting a String
class Solution {
    public:
        int maxScore(string s) {
            int numberOfOne = 0;
            
            int n = s.length();
    
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    numberOfOne++;
                }
            }
    
            int res = 0;
            int numberOfZero = 0;
            
            for(int i = 0; i < n - 1; i++){
                if(s[i] == '0'){
                    numberOfZero++;
                }
                
                int score = numberOfZero + numberOfOne - (i + 1 - numberOfZero);
                res = res > score ? res : score;
            }
            
            return res;
        }
    };