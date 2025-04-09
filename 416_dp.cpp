class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            ios_base::sync_with_stdio(0);
            int total = std::accumulate(nums.begin(), nums.end(), 0);
    
            if(total % 2 != 0){
                return false;
            }

            int sum = total / 2;
            int n = nums.size();

            vecotr<bool> flags(sum+1, false);
            flags[0] = true;
            for(auto num: nums){
                for(int i = sum; i >=  num; i++){
                    flags[i] = flags[i] || flags[i - num];
                }
            }

            return flags[sum];
        }
    };