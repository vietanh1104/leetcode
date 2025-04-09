class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            ios_base::sync_with_stdio(0);
            vector<pair<int, int>> pairs;
                
            unordered_set<int> flags(nums.begin(), nums.end());

            for(auto num: nums){
                if(flags.count(target - num) > 0){
                    pairs.push_back({num, target - num});
                }
            }

            vector<int> res;

            for(auto p: pairs){
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] == p.first || nums[i] == p.second){
                        res.push_back(i);
                    }
                }

                if(res.size() == 2){
                    break;
                }

                res.clear();
            }    
            
            flags.clear();
            pairs.clear();

            return res;
        }
    };