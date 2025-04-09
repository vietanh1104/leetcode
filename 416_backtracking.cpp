class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            ios_base::sync_with_stdio(0);
    
            if(nums.size() < 2){
                return false;
            }
    
            if(nums.size() == 2){
                if(nums[0] != nums[1]){
                    return false;
                }
                else{
                    return true;
                } 
            }
    
            int n = nums.size();
            std::vector<bool> flags(n, false);  // khởi tạo vector bool với n phần tử, tất cả đều false
    
            bool res = false;
            int total = std::accumulate(nums.begin(), nums.end(), 0);
    
            back_tracking(0, nums, flags, 0, total, res);
    
            return res;
        }
    
        // tle
        void back_tracking(int begin, vector<int> nums, vector<bool>& flags, int sum, int total, bool& res){
            if(res){
                return;
            }
            if(sum * 2  == total){
                res = true;
                return;
            }
            else if(sum * 2 > total){
                return;
            }
        
            for(int i = begin; i < nums.size(); i++){
                if(!flags[i]){
                    flags[i] = true;
                    back_tracking(i+1, nums, flags, sum + nums[i], total, res);
                    flags[i] = false;
                }
            }
        }
    };