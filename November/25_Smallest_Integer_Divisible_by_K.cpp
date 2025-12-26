// 1015. Smallest Integer Divisible by K

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 0;

        for(int len=1; len<=k; len++){
            num = (num*10 + 1) % k;
            if(num % k == 0) return len;
        }

        return -1;
    }
};/