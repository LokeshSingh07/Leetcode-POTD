// 1716. Calculate Money in Leetcode Bank

class Solution {
public:
    int totalMoney(int n) {
        int monday = 0;
        int amount = 0;

        while(n > 0){
            for(int d=1; d<=min(n,7); d++){
                amount += monday+ d;
            }

            monday++;
            n -= 7;
        }

        return amount;
    }
};