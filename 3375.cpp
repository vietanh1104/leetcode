class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            std::sort(nums.begin(), nums.end(), [](int a, int b) {
                return a > b;
            });
            int operating_time = 0;
            int processing_value = -1;
    
            for(auto& num: nums){
                if(num < k){
                    return -1;
                }
                else if (num == k){
                    continue;
                }else if(processing_value != num){
                    processing_value = num;
                    operating_time++;
                }    
            }
    
            return operating_time;
        }
    };