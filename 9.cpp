class Solution {
    public:
        bool isPalindrome(int x) {
            ios_base::sync_with_stdio(0);
            if(x < 0) return false;

            int reverse = 0;
            int temp = x;

            while(temp > 0){
                reverse = (reverse * 10) + x % 10;
                x /= 10;
            }
    
            return temp == reverse;
        }
    };