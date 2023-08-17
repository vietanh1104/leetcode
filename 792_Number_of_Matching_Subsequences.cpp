// medium
// max length of subsequences
// set

#include<bits/stdc++.h>
#include<set>
#include<unordered_set>

using namespace std;



class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        set<string> valid = {};
        set<string> invalid ={};
        for(auto word : words){
        	if(!valid.empty() && valid.find(word) != valid.end()){
        		count++;
			}
			else if(!invalid.empty() && invalid.find(word) != invalid.end()){
				continue;
			}
        	if(algorithm(s, word)){
        		count++;
        		valid.insert(word);
			}
			else{
				invalid.insert(word);
			}
		}
        
        return count;
    }
    bool algorithm(string s, string w){
    	int m = s.length();
    	int n = w.length();
    	
    	int i = 0;
        int j = 0;
        while(i < s.length() && j < w.length()){
            if(s[i] == w[j]){
                j++;
            }
            if(j == w.length()){
                return true;
            }
            i++;
        }
		return false;
	}
//    bool algorithm(string s, string w){
//    	int m = s.length();
//    	int n = w.length();
//    	
//    	int L[m+1][n+1];
//    	
//    	for(int i = 0; i <= m; i++){
//    		L[i][0] = 0;
//		}
//		for(int j = 0; j <= n; j++){
//    		L[0][j] = 0;
//		}
//		
//		for(int i = 1; i <= m; i++){
//			for(int j = 1; j <= n; j++){
//				if(s[i-1] == w[j-1]){
//					L[i][j] = L[i-1][j-1] +1;
//				}else
//					L[i][j] = max(L[i-1][j], L[i][j-1]);
//			}
//		}
//		return L[m][n] == n;
//	}
};

int main(){
	string s = "abcde";
	vector<string> words = {"a","bb","acd","ace"};
	Solution res;
	cout <<  res.numMatchingSubseq(s, words);
}
