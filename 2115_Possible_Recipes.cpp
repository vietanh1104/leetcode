class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            ios_base::sync_with_stdio(0);
            // add supply set
            unordered_set<string> is_available(supplies.begin(), supplies.end());
            vector<string> result;
            bool notDoneYet = true;
    
            while(notDoneYet){
                notDoneYet = false;
    
                for(int i = 0; i < recipes.size(); i++){
                    if(is_available.count(recipes[i])){
                        continue;
                    }
    
                    bool flags = true;
    
                    for(const string& ing: ingredients[i]){
                        if(!is_available.count(ing)){
                            flags = false; break;
                        }
                    }
    
                    if(flags){
                        is_available.insert(recipes[i]);
                        result.push_back(recipes[i]);
                        notDoneYet = true;
                    }
                }
            }
            
            return result;
        }
    };