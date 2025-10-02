// 3100. Water Bottles II


class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int consumedBottles = numBottles;

        while(numBottles >= numExchange){
            consumedBottles++;
            numBottles = (numBottles-numExchange) + 1;
            numExchange++;
        }

        return consumedBottles;
    }
};