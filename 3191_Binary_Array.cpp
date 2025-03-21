class Solution {
    public:
        int minOperations(vector<int>& nums) {  
            if(nums.size() < 3){
                return -1;
            }
    
            int result = 0;
            int length = nums.size();
    
            for(int i = 0; i < length - 2; i++){
                if(nums[i] == 0){
                    nums[i] = 1;
    
                    if(nums[i+1] == 0){
                        nums[i+1] = 1;
                    }
                    else{
                        nums[i+1] = 0;
                    }
    
                    if(nums[i+2] == 0){
                        nums[i+2] = 1;
                    }
                    else{
                        nums[i+2] = 0;
                    }
    
                    result++;
                }
            }
    
            if(nums[length - 1] == 1 && nums[length - 2] == 1){
                return result;
            }
    
            return -1;
        }
    };