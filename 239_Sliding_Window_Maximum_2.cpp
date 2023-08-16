// hard
// using double-ended queue;
#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution{
public :
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        
		 // init response variable
        vector<int> res;
		// init double-ended queue
		deque<int> q;
        for(int i=0;i<nums.size();i++){
        	// if the first element is out of the sliding window's size then pop it
            if(!q.empty() and q.front()==i-k) q.pop_front();
            // check if the last element of queue is smaller than nums[i] then pop it
            while(!q.empty() and nums[i]>nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        
       
        return res;
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	
	// input variables
	//int nums[] = {1,3,-1,-3,5,3,6,7}, k = 3;
	int nums[] = {1}, k = 1;
	
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

