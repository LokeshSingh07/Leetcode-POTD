// 1518. Water Bottles


// Approach-1: Brute force
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = numBottles;

        while(numBottles >= numExchange){
            consumedBottles += (numBottles / numExchange);
            int emptyBottles = (numBottles / numExchange) + (numBottles % numExchange);
            numBottles = emptyBottles;
        }

        return consumedBottles;
    }
};



// Approach-2: Optimal
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};