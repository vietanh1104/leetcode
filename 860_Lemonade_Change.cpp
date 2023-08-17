// easy
// queue

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    	int f = 0, t = 0;
    	
    	for(int money : bills){
    		if(money == 5)	f += 1;
			else if(money == 10){
				if(f < 1){
					return false;
				}
				f-= 1;
				t += 1;
			}else{
				if(f>0 && t>0){
					f -= 1;
					t -= 1;	
				}else if(f>=3){
					f -= 3;
				}
				else return false;
				
			}
		}
    	
    	
        return true;
    }
};

int main(){
	// input variables
	vector<int> inp = {5,5,10,10,20};

	Solution res;
	bool a = res.lemonadeChange(inp);
	if(a){
		cout << 1;
	}
	else{
		cout << 0;
	}

}
