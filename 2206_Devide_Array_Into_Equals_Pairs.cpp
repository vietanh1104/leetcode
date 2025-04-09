class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_set<int> storage;
    
            for(auto num : nums){
                if(storage.count(num)){
                    storage.erase(num);
                }
                else{
                    storage.insert(num);
                }
            }
    
            return storage.size() == 0;
        }
    };