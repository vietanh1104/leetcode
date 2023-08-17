// medium
// queue
// bfs

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     	
     	if(mat.empty() || mat[0].empty()){
			return {}; 
		}
     	
     	// col
     	int m = mat.size();
     	// row
     	int n = mat[0].size();
     	
     	queue<pair<int,int>> q;
     	
     	// first, q store 0 cell
     	for(int i = 0; i < m; i++){
     		for(int j = 0; j < n; j++){
     			if( mat[i][j] == 0){
     				q.push({i,j});
				}else{
					mat[i][j] = m+n;
				}
			}
		}
		
		// possible direction
		vector<pair<int, int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
		
		while(!q.empty()){
			
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			
			for(pair<int, int> direction : directions){
				
				int r = direction.first;
				int c = direction.second;
				
				int newRow= r+ row, newCol= c+ col;
				
                if(newRow>= 0 and newRow< m and newCol>= 0 and newCol< n and  mat[newRow][newCol]> mat[row][col]+ 1){
                    q.push({newRow,newCol});
                    mat[newRow][newCol]= mat[row][col]+1;
                }
			}
		}
		
     	
     	return mat;
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	
	// input variables
	vector<vector<int>> inp = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

	Solution res;
	vector<vector<int>> a = res.updateMatrix(inp);
	
	for(int i= 0; i< a.size(); i++){
		for(int j = 0; j < a[0].size(); j++){
			cout<< a[i][j] << " ";
		}
		cout << "\t";
	};
}

