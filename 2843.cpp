// 2843. Count Symmetric Integers
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            for(int i = low; i <= high; i++){
                if(i < 100){
                    if(i % 11 == 0){
                        res ++;
                    }
                }
                else if(i > 1000){
                    int l = i / 1000 + i % 1000 / 100;
                    int r = i % 10 + i / 10 % 10;
                    if(l == r){
                        res ++;
                    }
                }
            }
    
            return res;
        }
    };