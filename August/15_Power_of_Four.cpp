// 342. Power of Four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;

        for(int i=0; i<18; i++){
            if(pow(4, i) == n) return true;
        }

        return false;
    }
};