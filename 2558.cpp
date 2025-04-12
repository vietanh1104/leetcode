// 2558. Take Gifts From the Richest Pile
class Solution {
    public:
        long long pickGifts(vector<int>& gifts, int k) {
            while(k--){
                int richestGiftIndex = 0;
                for(int i = 1; i < gifts.size(); i++){
                    if(gifts[richestGiftIndex] < gifts[i]){
                        richestGiftIndex = i;
                    }
                }
    
                gifts[richestGiftIndex] = sqrt(gifts[richestGiftIndex]);
            }
    
            return (long long)accumulate(gifts.begin(), gifts.end(), 0LL);
        }
    };