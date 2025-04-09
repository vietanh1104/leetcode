class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            ios_base::sync_with_stdio(0);
    
            // Default sort by first element
            std::sort(meetings.begin(), meetings.end());
    
            int res = 0, flags = meetings[0][1];
    
            if(meetings[0][0] > 1){
                res += meetings[0][0] - 1;
            }
    
            for(int i = 1; i < meetings.size(); i++){
                if(flags < meetings[i][0] - 1){
                    res += meetings[i][0] - 1 - flags;
                    flags = meetings[i][1];
                }
                else if(flags < meetings[i][1]){
                    flags = meetings[i][1];
                    
                }
            }
    
            if(flags < days){
                res += days - flags;
            }
    
            return res;
        }
    };