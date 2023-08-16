// hard

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public :
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        
         // init response variable
        vector<int> res;
		
		if(nums.size() == 1 || k == 1){
			return nums;
		}
        int maxIndex= 0, i= 1;
        
        while(i < nums.size()){			
			if(i >= k - 1){
				if(nums[i] >= nums[maxIndex]){
					res.push_back(nums[i]);
				}else if(maxIndex > i - k) {
					res.push_back(nums[maxIndex]);
				}
				else{
					maxIndex = i-k+1;
					for(int l = i - k + 2; l <= i; l++){
						if(nums[l] > nums[maxIndex]){
			        		maxIndex = l;
						}
					}
					res.push_back(nums[maxIndex]);
				}
			}   
			 	
        	if(nums[i] >= nums[maxIndex]){
        		maxIndex = i;
			}
			
        	i++;
		}    
        return res;
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	
	// input variables
	//int nums[] = {1,3,-1,-3,5,3,6,7}, k = 3;
	int nums[] = {1}, k = 3;
	
	// convert input arr to vector
	vector<int> vec;
	int n = sizeof(nums) / sizeof(nums[0]);
	vec.insert(vec.begin(), nums, nums+n);
	
	Solution res;
	vector<int> a = res.maxSlidingWindow(vec,k);
	
	for(int i= 0; i< a.size(); i++){
		cout<< a[i];
	};
}

