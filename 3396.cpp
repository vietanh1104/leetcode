// Minimum Number of Operations to Make Elements in Array 
// unordered_set
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            ios_base::sync_with_stdio(0);
    
            int n = nums.size();
            if(n == 0){
                return 0;
            }
    
            if(n == 1){
                return 0;
            }
    
            unordered_set<int> s;
            int i ;
            bool flag = nums[n-1] == nums[n-2];
    
            for(i = 1; i <= n; i++){
                if(i > 1 && flag && nums[n-i] != nums[n-i+1]){
                    break;
                }
                else if(s.count(nums[n-i]) > 0){
                    break;
                }
                else{
                    s.insert(nums[n-i]);
                }
            }
    
            int skipped = n - i + 1;
    
            if(skipped % 3 == 0){
                return skipped / 3;
            }
            else{
                return skipped / 3 + 1;
            }
        }
    };