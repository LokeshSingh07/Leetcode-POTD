// 2749. Minimum Operations to Make the Integer Zero

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;

        while(true){
            long long val = (long long)num1 - (long long)t*num2;
            if(val < 0) return -1;
            if(__builtin_popcountl(val) <= t && t <= val) return t;

            t++;
        }

        return -1;
    }
};