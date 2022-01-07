
//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int r, rn = 0;
        while(x != 0){
            if (rn > INT_MAX/10 || rn < INT_MIN/10){
                return 0;
            }
            r = x % 10;
            rn = rn * 10  + r;
            x /= 10;
               
        }
        return rn;
        
    }
};
