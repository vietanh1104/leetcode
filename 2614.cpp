// 2614. Prime In Diagonal
class Solution {
    public:
        int diagonalPrime(vector<vector<int>>& nums) {
            int n = nums.size();
            int m = nums[0].size();
            int maxVal = 0;
    
            // Tìm giá trị lớn nhất trên 2 đường chéo để không tạo sieve quá lớn
            for (int i = 0; i < n; i++) {
                maxVal = max(maxVal, nums[i][i]);
                maxVal = max(maxVal, nums[i][m - 1 - i]);
            }
    
            vector<bool> flags(maxVal + 1, true);
            flags[0] = false;
            flags[1] = false;
            
            for (int i = 2; i * i <= maxVal; i++) {
                if (flags[i]) {
                    for (int j = 2 * i; j <= maxVal; j += i) {
                        flags[j] = false;
                    }
                }
            }
    
            int largestPrime = 0;
    
            for (int i = 0; i < n; ++i) {
                int a = nums[i][i];
                int b = nums[i][m - 1 - i];
                if (flags[a]) largestPrime = max(largestPrime, a);
                if (flags[b]) largestPrime = max(largestPrime, b);
            }
    
            return largestPrime;
        }
    };