// 374. Guess Number Higher or Lower

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 0;
        long right = n;
        int mid = (right + left + 1) / 2;
        
        int result = 0;
        while(result = guess(mid)){
            if(result == 1){
                left = mid;
            }else{
                right = mid;
            }
            mid = (right + left + 1) / 2;
        }
        
        return mid;
    }
};